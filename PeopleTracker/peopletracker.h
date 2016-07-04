#ifndef PEOPLETRACKER_H
#define PEOPLETRACKER_H

#include <QMainWindow>
#include <QListView>
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

private:
    Ui::peopleTracker *ui;
};

#endif // PEOPLETRACKER_H



