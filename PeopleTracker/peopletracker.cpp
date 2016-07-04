#include "peopletracker.h"
#include "ui_peopletracker.h"


peopleTracker::peopleTracker(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::peopleTracker)
{
    ui->setupUi(this);
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
    ui->maleRadio->setAutoExclusive(false);
    ui->maleRadio->setChecked(false);
    ui->maleRadio->setAutoExclusive(true);
    ui->femaleRadio->setAutoExclusive(false);
    ui->femaleRadio->setChecked(false);
    ui->femaleRadio->setAutoExclusive(true);
}

void peopleTracker::on_saveButton_clicked()
{
    /*QVariant Name = ui->nameEdit->text();
    ui->listView->model()->insertRow(1);
    //ui->listView->model->setData(ui->listView->model()->index(1), QVariant Name);
    */
}

