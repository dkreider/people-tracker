/***********
Tracks Tracker - A simple contact manager built with QT with potential to be expanded into something better...
    Copyright (C) 2016  Daniel Kreider

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***********/

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
#include <QSqlTableModel>
#include "backup.h"

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
    void copyDatabase();
    void eventLogger(QString text);
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

    void on_actionSave_triggered();

    void on_actionClose_triggered();

    void on_actionDelete_triggered();

    void on_actionFind_name_triggered();

    void on_saveButton_2_clicked();

    void on_updateButton_clicked();

    void on_searchBox_returnPressed();

    void on_actionRestore_triggered();

    void on_actionBackup_2_triggered();

private:
    Ui::peopleTracker *ui;
    QStringListModel *people;
    QStringList *List;
    backup *backupWindow;
};

#endif // PEOPLETRACKER_H



