#ifndef PEOPLETRACKER_H
#define PEOPLETRACKER_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>
#include <QStringList>
#include <QAbstractItemView>
#include "ui_peopletracker.h"


namespace Ui {
class peopleTracker;
}

class peopleTracker : public QMainWindow
{
    Q_OBJECT

public:
    explicit peopleTracker(QWidget *parent = 0);
    ~peopleTracker();

private slots:
    void on_clearButton_clicked();

    void on_saveButton_clicked();

    void on_deleteButton_clicked();

    void on_actionExit_triggered();

private:
    Ui::peopleTracker *ui;
    QStringListModel *model;
};

#endif // PEOPLETRACKER_H



