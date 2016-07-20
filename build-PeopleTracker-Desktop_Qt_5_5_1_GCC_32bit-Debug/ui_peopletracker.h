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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
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
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionClose;
    QAction *actionDelete;
    QAction *actionAbout;
    QAction *actionExit;
    QWidget *centralWidget;
    QListView *listView;
    QLineEdit *nameEdit;
    QLabel *nameLabel;
    QLineEdit *emailEdit;
    QLineEdit *trackingEdit;
    QLabel *emailLabel;
    QLabel *trackingLabel;
    QTextEdit *commentsEdit;
    QLabel *commentsLabel;
    QPushButton *saveButton;
    QPushButton *clearButton;
    QPushButton *deleteButton;
    QGroupBox *groupBox;
    QRadioButton *maleRadio;
    QRadioButton *femaleRadio;
    QTextEdit *addressEdit;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuType;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *peopleTracker)
    {
        if (peopleTracker->objectName().isEmpty())
            peopleTracker->setObjectName(QStringLiteral("peopleTracker"));
        peopleTracker->resize(751, 607);
        QIcon icon;
        icon.addFile(QStringLiteral("footprint.png"), QSize(), QIcon::Normal, QIcon::Off);
        peopleTracker->setWindowIcon(icon);
        actionOpen = new QAction(peopleTracker);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionNew = new QAction(peopleTracker);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionSave = new QAction(peopleTracker);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionClose = new QAction(peopleTracker);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionDelete = new QAction(peopleTracker);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionAbout = new QAction(peopleTracker);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionExit = new QAction(peopleTracker);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(peopleTracker);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(10, 0, 221, 531));
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
        commentsEdit = new QTextEdit(centralWidget);
        commentsEdit->setObjectName(QStringLiteral("commentsEdit"));
        commentsEdit->setGeometry(QRect(270, 350, 471, 131));
        commentsLabel = new QLabel(centralWidget);
        commentsLabel->setObjectName(QStringLiteral("commentsLabel"));
        commentsLabel->setGeometry(QRect(270, 320, 81, 17));
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(260, 500, 99, 27));
        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(390, 500, 99, 27));
        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(520, 500, 99, 27));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(240, 210, 120, 80));
        maleRadio = new QRadioButton(groupBox);
        maleRadio->setObjectName(QStringLiteral("maleRadio"));
        maleRadio->setGeometry(QRect(10, 20, 81, 22));
        femaleRadio = new QRadioButton(groupBox);
        femaleRadio->setObjectName(QStringLiteral("femaleRadio"));
        femaleRadio->setGeometry(QRect(10, 50, 81, 22));
        addressEdit = new QTextEdit(centralWidget);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));
        addressEdit->setGeometry(QRect(370, 200, 351, 101));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(370, 180, 67, 17));
        peopleTracker->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(peopleTracker);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 751, 25));
        menuType = new QMenu(menuBar);
        menuType->setObjectName(QStringLiteral("menuType"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        peopleTracker->setMenuBar(menuBar);
        mainToolBar = new QToolBar(peopleTracker);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        peopleTracker->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(peopleTracker);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        peopleTracker->setStatusBar(statusBar);

        menuBar->addAction(menuType->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuType->addSeparator();
        menuType->addAction(actionOpen);
        menuType->addAction(actionNew);
        menuType->addAction(actionExit);
        menuEdit->addAction(actionSave);
        menuEdit->addAction(actionClose);
        menuEdit->addAction(actionDelete);
        menuHelp->addAction(actionAbout);

        retranslateUi(peopleTracker);

        QMetaObject::connectSlotsByName(peopleTracker);
    } // setupUi

    void retranslateUi(QMainWindow *peopleTracker)
    {
        peopleTracker->setWindowTitle(QApplication::translate("peopleTracker", "Tracks Tracker", 0));
#ifndef QT_NO_TOOLTIP
        peopleTracker->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        actionOpen->setText(QApplication::translate("peopleTracker", "New", 0));
        actionNew->setText(QApplication::translate("peopleTracker", "Open", 0));
        actionSave->setText(QApplication::translate("peopleTracker", "Save", 0));
        actionClose->setText(QApplication::translate("peopleTracker", "Close", 0));
        actionDelete->setText(QApplication::translate("peopleTracker", "Delete", 0));
        actionAbout->setText(QApplication::translate("peopleTracker", "About", 0));
        actionExit->setText(QApplication::translate("peopleTracker", "Exit", 0));
        nameLabel->setText(QApplication::translate("peopleTracker", "Full Name:", 0));
        emailLabel->setText(QApplication::translate("peopleTracker", "Email Address", 0));
        trackingLabel->setText(QApplication::translate("peopleTracker", "Tracking Number", 0));
        commentsLabel->setText(QApplication::translate("peopleTracker", "Comments:", 0));
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("peopleTracker", "Save customer...", 0));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QApplication::translate("peopleTracker", "Save", 0));
        saveButton->setShortcut(QApplication::translate("peopleTracker", "Ctrl+S", 0));
#ifndef QT_NO_TOOLTIP
        clearButton->setToolTip(QApplication::translate("peopleTracker", "Clear current screen.", 0));
#endif // QT_NO_TOOLTIP
        clearButton->setText(QApplication::translate("peopleTracker", "Clear", 0));
        clearButton->setShortcut(QApplication::translate("peopleTracker", "Ctrl+N", 0));
        deleteButton->setText(QApplication::translate("peopleTracker", "Delete", 0));
        groupBox->setTitle(QApplication::translate("peopleTracker", "Male \\ Female", 0));
        maleRadio->setText(QApplication::translate("peopleTracker", "Male", 0));
        femaleRadio->setText(QApplication::translate("peopleTracker", "Female", 0));
        label->setText(QApplication::translate("peopleTracker", "Address:", 0));
        menuType->setTitle(QApplication::translate("peopleTracker", "File", 0));
        menuEdit->setTitle(QApplication::translate("peopleTracker", "Edit", 0));
        menuHelp->setTitle(QApplication::translate("peopleTracker", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class peopleTracker: public Ui_peopleTracker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEOPLETRACKER_H
