#include "peopletracker.h"
#include "ui_peopletracker.h"


peopleTracker::peopleTracker(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::peopleTracker)
{
    ui->setupUi(this);
    people = new QStringListModel(this);
    // Load names
    loadNames("people.db");
}


peopleTracker::~peopleTracker()
{
    delete ui;
}


//Clear all edit fields.
void peopleTracker::on_clearButton_clicked()
{
    ui->nameEdit->clear();
    ui->emailEdit->clear();
    ui->trackingEdit->clear();
    ui->commentsEdit->clear();
    ui->addressEdit->clear();
}

void peopleTracker::on_saveButton_clicked()
{
    // Make sure we have at least a name.
    if(ui->nameEdit->text() == NULL) {
        QMessageBox::warning(this,
                             tr("More info needed"),
                             tr("I need at least a name before I can save the person."),
                             QMessageBox::Ok);
        ui->nameEdit->setFocus();
        return;
    }
    else {
        // open database.
        QSqlDatabase database;
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("people.db");


        if (!database.open())
        {
            QMessageBox::critical(this,
                            tr("SQL open error"),
                            database.lastError().text());
            database.close();
            return;

        }

        else {
            QSqlQuery query;
            QString name = ui->nameEdit->text();
            query.prepare("SELECT name FROM people WHERE name = (:name)");
            query.bindValue(":name", name);
            // Check to make sure name does not exist. If it exists we update the record. Otherwise we add it.
            if(query.exec()) {
                if(query.next()) {
                    QMessageBox::warning(this,
                                         tr("Error!"),
                                         tr("The name you tried to save already exists in the database."),
                                         QMessageBox::Ok);
                    return;
                }
                // Add record
                else {
                        QString name = ui->nameEdit->text();
                        QString email = ui->emailEdit->text();
                        QString trackingNumber = ui->trackingEdit->text();
                        QString address = ui->addressEdit->toPlainText();
                        QString comments = ui->commentsEdit->toPlainText();
                        QSqlQuery add;
                        add.prepare("INSERT INTO people (name, email, trackingNumber, address, comments) VALUES (:name, :email, :trackingNumber, :address, :comments)");
                        add.bindValue(":name", name);
                        add.bindValue(":email", email);
                        add.bindValue(":trackingNumber", trackingNumber);
                        add.bindValue(":address", address);
                        add.bindValue(":comments", comments);
                        if(add.exec()) {
                            loadNames("people.db");                           
                            on_clearButton_clicked();
                            database.close();
                            return;
                        }
                        else {
                            QMessageBox::critical(this,
                                            tr("SQL Insert error"),
                                            add.lastError().text());
                            database.close();
                        }
                 }
            }
        }
    }
}

// Removed selected person in listView.
void peopleTracker::on_deleteButton_clicked()
{
    // Make sure a person is selected.
    if(ui->nameEdit->text() == NULL) {
        QMessageBox::warning(this,
                             tr("Not selected"),
                             tr("Unable to delete because nobody is selected."),
                             QMessageBox::Ok);
        return;
    }

    else {
        QSqlDatabase database;
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("people.db");


        if (!database.open())
        {
            QMessageBox::critical(this,
                            tr("SQL open error"),
                            database.lastError().text());
            database.close();
            return;

        }

        else {
            int response = QMessageBox::warning(this,
                                 tr("Warning"),
                                 tr("Are you sure you want to remove the selected person?"),
                                 QMessageBox::Yes, QMessageBox::No);

            if(response == QMessageBox::Yes) {
                QSqlQuery query;
                QString name = on_listView_clicked();
                query.prepare("DELETE FROM people WHERE name = (:name)");
                query.bindValue(":name", name);
                if(query.exec()) {
                    // Query executed successfully. Reload database to reflect changes.
                    loadNames("people.db");
                    // Clear screen.
                    peopleTracker::on_clearButton_clicked();
                    database.close();
                    return;
                }
                else {
                    QMessageBox::critical(this,
                                    tr("SQL Delete error"),
                                    query.lastError().text());
                    database.close();
                }
            }
            else {
                database.close();
                return;
            }
        }
    }
}


// Load names from DataBase.
void peopleTracker::loadNames(QString path_to_database)
{
    QStringList names;
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(path_to_database);


    if (!database.open())
    {
        QMessageBox::critical(this,
                        tr("SQL open error"),
                        database.lastError().text());
        database.close();
        return;

    }
    else
    {
        // Load name column from people table.
        QSqlQuery query("SELECT name FROM people");
        int idName = query.record().indexOf("name");
        while (query.next())
        {
            QString name = query.value(idName).toString();
            names.append(name);
        }
        // Glue model and listView together
        people->setStringList(names);
        ui->listView->setModel(people);
    }
    database.close();
}

// Stolen example from http://stackoverflow.com/questions/18093156/how-do-i-get-the-items-selected-from-a-qlistview
// Used to return selected person from listView.
QString peopleTracker::on_listView_clicked()
{
    QModelIndexList list = ui->listView->selectionModel()->selectedIndexes();
    QStringList names;
    foreach (const QModelIndex &index, list) {
       names.append(index.data(Qt::DisplayRole).toString());
    }
    return names.join("");
}

// Stolen example from http://stackoverflow.com/questions/18093156/how-do-i-get-the-items-selected-from-a-qlistview
// Used to return rest of person's data from DB after being selected in the listView.
void peopleTracker::on_listView_clicked(const QModelIndex &index)
{
    QModelIndexList list = ui->listView->selectionModel()->selectedIndexes();
    QStringList names;
    foreach (const QModelIndex &index, list) {
       names.append(index.data(Qt::DisplayRole).toString());
    }

    QString name = names.join("");
    ui->nameEdit->setText(name);
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("people.db");

    if (!database.open())
    {
        QMessageBox::critical(this,
                              tr("Unable to open database."),
                              database.lastError().text());
        database.close();

    }
    /*******
     * I do not like the logic in the following else statement but have yet to find a better implementation.
     * Basically we query each record in the DB till we find the record that matches the value of the selected
     * listView item. We then grab the email, trackingNumber, etc... from the query that returns a name that
     * matches the value of the selected item in the listView.
     ******/
    else {
        QSqlQuery query;
        query.exec("SELECT name, email, trackingNumber, address, comments FROM people");
        while (query.next())
        {
            QString returnedName = query.value(0).toString();
            QString returnedEmail = query.value(1).toString();
            QString returnedTrackingNumber = query.value(2).toString();
            QString returnedAddress = query.value(3).toString();
            QString returnedComment = query.value(4).toString();
            /******
             *  Compare value of selected name with the name the query returned.
             *  If they're the same then we grab email, tracking Number, etc...
             *  from the same query.
             ******/
            int x = QString::compare(name, returnedName);
            if(x == 0) {
                ui->emailEdit->setText(returnedEmail);
                ui->trackingEdit->setText(returnedTrackingNumber);
                ui->addressEdit->setText(returnedAddress);
                ui->commentsEdit->setText(returnedComment);
            }
            else {
                // Do nothing.
            }
        }
        database.close();
   }
}


// Event to close the application via File -> Close.
void peopleTracker::on_actionExit_triggered()
{
    QMainWindow::close();
}

// About box via Help -> About.
void peopleTracker::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About Tracks Tracker"),
            tr("<h2>Tracks Tracker 0.1</h2>"
            "<p>Copyright &copy; 2016 <br>"
            "<p>People Tracker is a simple application "
            "that endevours to give users an easy way "
            "to track customer data."));
}

void peopleTracker::on_actionSave_triggered()
{
    on_saveButton_clicked();
}

void peopleTracker::on_actionClose_triggered()
{
    on_clearButton_clicked();
}

void peopleTracker::on_actionDelete_triggered()
{
    on_deleteButton_clicked();
}

void peopleTracker::on_actionFind_name_triggered()
{

}

void peopleTracker::on_updateButton_clicked()
{
    // Make sure a name is selected
    if(ui->nameEdit->text() == NULL) {
        QMessageBox::warning(this,
                             tr("Error"),
                             tr("I cannot update anything if no customer is selected"),
                             QMessageBox::Ok);
        return;
    }
    // open database.
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("people.db");


    if (!database.open())
    {
        QMessageBox::critical(this,
                        tr("SQL open error"),
                        database.lastError().text());
        database.close();
        return;

    }

    else {
        QSqlQuery query;
        QString name = ui->nameEdit->text();
        query.prepare("SELECT name FROM people WHERE name = (:name)");
        query.bindValue(":name", name);
        // Check to make sure name does not exist. If it exists we update the record. Otherwise we add it.
        if(query.exec()) {
            if(query.next()) {

                    QString name = ui->nameEdit->text();
                    QString email = ui->emailEdit->text();
                    QString trackingNumber = ui->trackingEdit->text();
                    QString address = ui->addressEdit->toPlainText();
                    QString comments = ui->commentsEdit->toPlainText();
                    QString selectedName = on_listView_clicked();
                    QSqlQuery update;
                    update.prepare("UPDATE people SET name = (:name), email = (:email), trackingNumber = (:trackingNumber), address = (:address), comments = (:comments) WHERE name = (:selectedName)");
                    update.bindValue(":name", name);
                    update.bindValue(":email", email);
                    update.bindValue(":trackingNumber", trackingNumber);
                    update.bindValue(":address", address);
                    update.bindValue(":comments", comments);
                    update.bindValue(":selectedName", selectedName);
                    if(update.exec()) {
                        loadNames("people.db");
                        // clear screen.
                        on_clearButton_clicked();
                        database.close();
                        return;
                    }
              }
            else {
                QMessageBox::warning(this,
                                     tr("Error"),
                                     tr("Unable update customer because it does not exist in database."),
                                     QMessageBox::Ok);
                return;
            }
         }
     }
}
