/********************************************************************************
** Form generated from reading UI file 'peopletracker.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEOPLETRACKER_H
#define UI_PEOPLETRACKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_peopleTracker
{
public:
    QWidget *centralWidget;
    QListView *listView;
    QLineEdit *nameEdit;
    QLabel *nameLabel;
    QLineEdit *emailEdit;
    QLineEdit *trackingEdit;
    QLabel *emailLabel;
    QLabel *trackingLabel;
    QRadioButton *maleRadio;
    QRadioButton *femaleRadio;
    QTextEdit *commentsEdit;
    QLabel *commentsLabel;
    QPushButton *saveButton;
    QPushButton *clearButton;
    QPushButton *deleteButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *peopleTracker)
    {
        if (peopleTracker->objectName().isEmpty())
            peopleTracker->setObjectName(QStringLiteral("peopleTracker"));
        peopleTracker->resize(751, 562);
        QIcon icon;
        icon.addFile(QStringLiteral("../../Downloads/footprint.png"), QSize(), QIcon::Normal, QIcon::Off);
        peopleTracker->setWindowIcon(icon);
        centralWidget = new QWidget(peopleTracker);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(10, 0, 221, 441));
        nameEdit = new QLineEdit(centralWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(330, 30, 391, 31));
        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(250, 30, 67, 17));
        emailEdit = new QLineEdit(centralWidget);
        emailEdit->setObjectName(QStringLiteral("emailEdit"));
        emailEdit->setGeometry(QRect(350, 80, 371, 31));
        trackingEdit = new QLineEdit(centralWidget);
        trackingEdit->setObjectName(QStringLiteral("trackingEdit"));
        trackingEdit->setGeometry(QRect(370, 130, 351, 31));
        emailLabel = new QLabel(centralWidget);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));
        emailLabel->setGeometry(QRect(240, 80, 101, 17));
        trackingLabel = new QLabel(centralWidget);
        trackingLabel->setObjectName(QStringLiteral("trackingLabel"));
        trackingLabel->setGeometry(QRect(240, 130, 121, 17));
        maleRadio = new QRadioButton(centralWidget);
        maleRadio->setObjectName(QStringLiteral("maleRadio"));
        maleRadio->setGeometry(QRect(370, 200, 81, 22));
        femaleRadio = new QRadioButton(centralWidget);
        femaleRadio->setObjectName(QStringLiteral("femaleRadio"));
        femaleRadio->setGeometry(QRect(370, 240, 81, 22));
        commentsEdit = new QTextEdit(centralWidget);
        commentsEdit->setObjectName(QStringLiteral("commentsEdit"));
        commentsEdit->setGeometry(QRect(270, 300, 471, 131));
        commentsLabel = new QLabel(centralWidget);
        commentsLabel->setObjectName(QStringLiteral("commentsLabel"));
        commentsLabel->setGeometry(QRect(270, 270, 81, 17));
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(260, 450, 99, 27));
        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(390, 450, 99, 27));
        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(510, 450, 99, 27));
        peopleTracker->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(peopleTracker);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 751, 25));
        peopleTracker->setMenuBar(menuBar);
        mainToolBar = new QToolBar(peopleTracker);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        peopleTracker->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(peopleTracker);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        peopleTracker->setStatusBar(statusBar);

        retranslateUi(peopleTracker);

        QMetaObject::connectSlotsByName(peopleTracker);
    } // setupUi

    void retranslateUi(QMainWindow *peopleTracker)
    {
        peopleTracker->setWindowTitle(QApplication::translate("peopleTracker", "People Tracker", 0));
        nameLabel->setText(QApplication::translate("peopleTracker", "Full Name:", 0));
        emailLabel->setText(QApplication::translate("peopleTracker", "Email Address", 0));
        trackingLabel->setText(QApplication::translate("peopleTracker", "Tracking Number", 0));
        maleRadio->setText(QApplication::translate("peopleTracker", "Male", 0));
        femaleRadio->setText(QApplication::translate("peopleTracker", "Female", 0));
        commentsLabel->setText(QApplication::translate("peopleTracker", "Comments:", 0));
        saveButton->setText(QApplication::translate("peopleTracker", "Save", 0));
        clearButton->setText(QApplication::translate("peopleTracker", "Clear", 0));
        deleteButton->setText(QApplication::translate("peopleTracker", "Delete", 0));
    } // retranslateUi

};

namespace Ui {
    class peopleTracker: public Ui_peopleTracker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEOPLETRACKER_H
