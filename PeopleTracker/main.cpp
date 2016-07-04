#include "peopletracker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    peopleTracker w;
    w.show();

    return a.exec();
}
