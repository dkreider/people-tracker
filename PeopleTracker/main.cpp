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
