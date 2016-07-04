#include "peopletracker.h"
#include "ui_peopletracker.h"


peopleTracker::peopleTracker(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::peopleTracker)
{
    ui->setupUi(this);

    // Create model.
    model = new QStringListModel(this);
    // Glue model and listView together
    QStringList List;
    List << "1st person" << "2nd person" << "3rd person";
    model->setStringList(List);
    ui->listView->setModel(model);

    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);
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
    /*
    // Get the position.
    int row = ui->listView->currentIndex().row();
    // Enable the addition of more rows.
    model->insertRows(row, 1);
    // Get row for edit mode.
    QModelIndex index = model->index(row);
    // Enable item selection and put it in edit mode.
    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index); */
}


void peopleTracker::on_deleteButton_clicked()
{
    model->removeRows(ui->listView->currentIndex().row(), 1);
}
