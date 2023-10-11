#include "interface.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    interface w;
    w.show();
    return a.exec();
}
