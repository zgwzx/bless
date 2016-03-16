#include "boolcal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    boolcal w;
    w.show();

    return a.exec();
}
