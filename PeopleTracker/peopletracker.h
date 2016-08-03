#ifndef PEOPLETRACKER_H
#define PEOPLETRACKER_H

//#define NAME_DATA_BASE data.txt

#include <QMainWindow>
#include <QListView>
#include <QList>
#include <QStringListModel>
#include <QStringList>
#include <QAbstractItemView>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QModelIndex>

namespace Ui {
class peopleTracker;
}

class peopleTracker : public QMainWindow
{
    Q_OBJECT

public:
    explicit peopleTracker(QWidget *parent = 0);
    void appendNameToDataBase(QString Name);
    void addPerson(QString Name);
    void loadNames(QString path_to_database);
    QString isPersonSelected();

    ~peopleTracker();

private slots:
    void on_clearButton_clicked();

    void on_saveButton_clicked();

    void on_deleteButton_clicked();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionLoad_customers_triggered();

    QString on_listView_clicked();

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::peopleTracker *ui;
    QStringListModel *people;
    QStringList *List;
};

#endif // PEOPLETRACKER_H



