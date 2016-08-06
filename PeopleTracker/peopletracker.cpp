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
    ui->maleRadio->setAutoExclusive(false);
    ui->maleRadio->setChecked(false);
    ui->maleRadio->setAutoExclusive(true);
    ui->femaleRadio->setAutoExclusive(false);
    ui->femaleRadio->setChecked(false);
    ui->femaleRadio->setAutoExclusive(true);
}

void peopleTracker::on_saveButton_clicked()
{
    // Make sure we have at least a name.
    if(ui->nameEdit->text() == NULL) {
        QMessageBox warning;
        warning.setText("I need at least a name before I can save the person.");
        warning.exec();
        ui->nameEdit->setFocus();
    }
    else {
        QSqlQuery query;
        QString name = ui->nameEdit->text();
        query.prepare("SELECT name FROM people WHERE name = (:name)");
        query.bindValue(":name", name);
        // Check to make sure name does not exist.
        if(query.exec()) {
            if(query.next()) {
                int response = QMessageBox::warning(this,
                                     tr("Notice"),
                                     tr("The name you want to save already exists in the database. Press OK to update person or Cancel to cancel the update."),
                                     QMessageBox::Ok,
                                     QMessageBox::Cancel);
                if(response == QMessageBox::Ok) {
                    // update records.
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
                        return;
                    }
                    else {
                        QMessageBox::warning(this,
                                             tr("Error"),
                                             tr("An unknown error occured while trying to update database."),
                                             QMessageBox::Ok);
                        return;
                    }
                }
                else {
                    return;
                }
            }
            // Add name to database
            else {
                    QString name = ui->nameEdit->text();
                    QString email = ui->emailEdit->text();
                    QString trackingNumber = ui->trackingEdit->text();
                    QString address = ui->addressEdit->toPlainText();
                    QString comments = ui->commentsEdit->toPlainText();
                    query.prepare("INSERT INTO people (name, email, trackingNumber, address, comments) VALUES (:name, :email, :trackingNumber, :address, :comments)");
                    query.bindValue(":name", name);
                    query.bindValue(":email", email);
                    query.bindValue(":trackingNumber", trackingNumber);
                    query.bindValue(":address", address);
                    query.bindValue(":comments", comments);
                    if(query.exec()) {
                        // Query executed successfully. Reload database to reflect changes.
                        loadNames("people.db");
                        return;
                    }
                    else {
                        QMessageBox::warning(this,
                                        tr("Error"),
                                        tr("An unknown error occurred while trying to add person to database."),
                                        QMessageBox::Ok);
                        qDebug() << query.lastError();
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
                return;
            }
            else {
                QMessageBox::warning(this,
                                     tr("Error"),
                                     tr("An unknown error occurred while trying to remove person from database."),
                                     QMessageBox::Ok);
                qDebug() << query.lastError();
            }
        }
        else {
            return;
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
        QMessageBox error;
        error.setText("Unable to open database.");
        error.exec();
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
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("people.db");

    if (!database.open())
    {
        QMessageBox error;
        error.setText("Unable to open database.");
        error.exec();

    }
    else {
        QSqlQuery nameQuery;
        QString email;
        nameQuery.prepare("SELECT name AND email FROM people WHERE name = (:name)");
        nameQuery.bindValue(":name", name);
        nameQuery.bindValue(":email", email);
        if(nameQuery.exec()) {
            ui->nameEdit->setText(name);
            ui->emailEdit->setText(email);
        }
        else {
            QMessageBox::warning(this,
                            tr("Error"),
                            tr("Uknown error getting name from database."),
                            QMessageBox::Ok);
            qDebug() << nameQuery.lastError();
        }
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
