#include "peopletracker.h"
#include "ui_peopletracker.h"


peopleTracker::peopleTracker(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::peopleTracker)
{
    ui->setupUi(this);
    /***********
     * We begin by opening the data file that contains all names and then insert those names into
     * the list view.
     **********/
    QString customerNames("names.txt");
    loadNames(customerNames);

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
    // Make sure we at least have a name.
    if(ui->nameEdit->text() == NULL) {
        QMessageBox::warning(this,
                             tr("More info needed!"),
                             tr("We need at least a name before we can save the customer."),
                             QMessageBox::Ok);
        ui->nameEdit->setFocus();
    }
    else {
        // Add name to end of name database file.
        QFile nameDataBase("names.txt");
        if(!nameDataBase.open(QIODevice::Append)) {
            QMessageBox::warning(this,
                                 tr("Error!"),
                                 tr("Sorry but an error occurred while trying to open database to remove name."),
                                 QMessageBox::Ok);
        }
        else {
            QString name = ui->nameEdit->text();
            if(nameDataBase.size() == 0) {
                QTextStream out(&nameDataBase);
                out << name;
            }
            else {
                QTextStream out(&nameDataBase);
                out << "\n" << name;
            }
            // Reload database to view changes.
            loadNames("names.txt");
            // Close file.
            nameDataBase.close();
        }
    }
}

// Removed selected person in listView.
void peopleTracker::on_deleteButton_clicked()
{
    int response = QMessageBox::warning(this, tr("Are you sure?"),
                                        tr("Are you sure you want to delete this person?\n"),
                                        QMessageBox::Yes,
                                        QMessageBox::No);
    if(response == QMessageBox::Yes) {
        // Open database file.
        QFile nameDataBase("names.txt");
        if(!nameDataBase.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QMessageBox::warning(this,
                                 tr("Error!"),
                                 tr("Sorry but an error occurred while trying to open database to remove name."),
                                 QMessageBox::Ok);
        }
        else {
            // Remove name from database file.
        }
        // Reload database to view changes.
        loadNames("names.txt");
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

void peopleTracker::loadNames(QString fileName)
{
    //QFile nameList("names.txt");
    QFile nameDataBase(fileName);
    QStringList names;
    if(!nameDataBase.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this,
                             tr("Error"),
                             tr("There was an error opening the list of customer names."),
                             QMessageBox::Ok);
    }

    else {
        QTextStream in(&nameDataBase);
        while(!in.atEnd()) {
            names.append(in.readLine());
            // Create model.
            people = new QStringListModel(this);
            // Glue model and listView together
            people->setStringList(names);
            ui->listView->setModel(people);
            nameDataBase.close();
        }
    }
}
