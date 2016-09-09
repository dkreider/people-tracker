
# Tracks Tracker - A simple contact manager built with QT with potential to be expanded into something better...
#   Copyright (C) 2016  Daniel Kreider
#
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.


#-------------------------------------------------
#
# Project created by QtCreator 2016-07-04T13:02:19
#
#-------------------------------------------------

QT       += core gui
QT       += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PeopleTracker
TEMPLATE = app


SOURCES += main.cpp\
        peopletracker.cpp \
    backup.cpp \
    restore.cpp

HEADERS  += peopletracker.h \
    backup.h \
    restore.h

FORMS    += peopletracker.ui \
    backup.ui \
    restore.ui
