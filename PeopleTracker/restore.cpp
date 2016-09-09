#include "restore.h"
#include "ui_restore.h"

restore::restore(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::restore)
{
    ui->setupUi(this);
}

restore::~restore()
{
    delete ui;
}

void restore::on_exitButton_clicked()
{
    restore::close();
}

void restore::on_restoreButton_clicked()
{
    if(ui->lineWhere->text() == NULL) {
        QMessageBox::warning(this,
                             tr("Error"),
                             tr("Please select a previous backup by clicking Browse."),
                             QMessageBox::Ok);
        return;
    }

    else {
        int response = QMessageBox::warning(this,
                                            tr("Warning!"),
                                            tr("By restoring a previous database you will loose all current contacts if you have any. Press OK to continue or Cancel to abort the restoration."),
                                            QMessageBox::Ok, QMessageBox::Cancel);

        if(response == QMessageBox::Ok) {
            QString restorePath = ui->lineWhere->text();
            QFile newDatabase("people.db");
            QFile database(restorePath);

            if(!database.open(QIODevice::ReadOnly)) {
                QMessageBox::warning(this,
                                     tr("Error!"),
                                     tr("Error opening selected database to import data."),
                                     QMessageBox::Ok);
                return;
            }

           if(!newDatabase.open(QIODevice::WriteOnly)) {
                QMessageBox::warning(this,
                                     tr("Error!"),
                                     tr("Error while trying to open database to restore contacts."),
                                     QMessageBox::Ok);
                return;
            }

           if(newDatabase.write(database.readAll())) {
               QMessageBox::information(this,
                                        tr("Success!"),
                                        tr("Successfully restored your contacts. Please restart Tracks Tracker to reflect the changes."),
                                        QMessageBox::Ok);
                       restore::close();
            }

            else {
               QMessageBox::warning(this,
                                     tr("Error!"),
                                     tr("Error writing contacts from backup to database. Maybe you tried importing the database that you're actually using?"),
                                     QMessageBox::Ok);
                return;
            }
        }

        else {
            restore::close();
        }
    }
}

void restore::on_browseButton_clicked()
{
    QString restoreFile = QFileDialog::getOpenFileName(this,
                                                       tr("Open backup..."),
                                                       (""),
                                                       tr("*.db"));
    ui->lineWhere->setText(restoreFile);
}
