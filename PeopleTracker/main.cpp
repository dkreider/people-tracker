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

#include "peopletracker.h"
#include <QApplication>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    peopleTracker w;
    QTableView tableView;
    w.show();

    return a.exec();
}
