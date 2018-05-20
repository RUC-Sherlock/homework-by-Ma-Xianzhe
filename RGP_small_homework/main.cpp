#include "world.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    World w;
    w.show();

    return a.exec();
}
