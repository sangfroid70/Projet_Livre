#include <QtGui/QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include "fenetre.h"

int main(int argc, char *argv[])
{
    QApplication appli(argc, argv);
    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    appli.installTranslator(&translator);

    Fenetre fenetrePrincipale;
    fenetrePrincipale.show();

    return appli.exec();
}
