#ifndef RESTORE_H
#define RESTORE_H

#include <QWidget>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlDatabase>

namespace Ui {
class restore;
}

class restore : public QWidget
{
    Q_OBJECT

public:
    explicit restore(QWidget *parent = 0);
    ~restore();

private slots:

    void on_exitButton_clicked();

    void on_restoreButton_clicked();

    void on_browseButton_clicked();

private:
    Ui::restore *ui;
};

#endif // RESTORE_H
