#include "peopletracker.h"
#include "ui_peopletracker.h"


peopleTracker::peopleTracker(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::peopleTracker)
{
    ui->setupUi(this);
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
    QSqlQuery query;
    QString name = ui->nameEdit->text();
    query.prepare("INSERT INTO people (name) VALUES (:name)");
    query.bindValue(":name", name);
    if(query.exec()) {
        // Do nothing.
    }
    else {
        QMessageBox::warning(this,
                        tr("Error"),
                        tr("Error adding another person to database."),
                        QMessageBox::Ok);
    }
    loadNames("people.db");
}

// Removed selected person in listView.
void peopleTracker::on_deleteButton_clicked()
{

}


// Load names from DataBase.
void peopleTracker::loadNames(QString path_to_database)
{
    people = new QStringListModel(this);
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(path_to_database);


    if (!database.open())
    {
        QMessageBox error;
        error.setText("Unable to open database.");
        error.exec();

    }
    else
    {
        // Load data from database.
        QStringList names;
        QSqlQuery query("SELECT * FROM people");
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
