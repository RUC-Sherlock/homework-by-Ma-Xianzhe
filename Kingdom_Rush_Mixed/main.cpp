#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.setFixedSize(1200,1000);
    w.show();

    return a.exec();
}
