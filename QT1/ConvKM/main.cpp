#include "convkm.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConvKM w;
    w.show();
    return a.exec();
}
