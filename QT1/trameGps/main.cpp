#include "tramegps.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    trameGps w;
    w.show();
    return a.exec();
}
