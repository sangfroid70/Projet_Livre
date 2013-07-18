#include "fichier.h"

Fichier::Fichier(QObject *parent) :
    QObject(parent)
{
}

Fichier::~Fichier () {

}

QString Fichier::charger (QString const &nomFichier) {
    QFile fichier (QCoreApplication::applicationDirPath() + "/texte/" + nomFichier);
    QString texte;
    if (!fichier.open(QIODevice::ReadOnly | QIODevice::Text))
        return QString("Cette page n'existe pas");

    QTextStream in(&fichier);
    texte = in.readAll();
    return texte;
}
