#include <QtGui/QApplication>
#include "mycrypt.h"
#include <QDebug>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel widget;
    widget.setMinimumSize(200,200);
    MyCrypt w("codage.txt");

    w.sauvegarderCrypter();
    widget.show();
    return a.exec();
}
