#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    qsrand(time(0));
    QApplication appli(argc, argv);
    MainWindow windows;
    windows.show();

    return appli.exec();
}
