#ifndef MyCRYPT_H
#define MyCRYPT_H
#include <QDebug>
#include <fstream>
#include <QFile>
#include <QByteArray>

class MyCrypt
{
public:
    explicit MyCrypt (const QString &nomFichier);
    ~MyCrypt ();
    const QString chargerDecrypter ();
    void sauvegarderCrypter ();

    static QString crypter (const QString &chaineEntree , int decalage = 1);
    static QString decrypter (const QString &chaineEntree , int decalage = 1);

private:
    QString m_nomFichier;
    QString m_nomFichierSortie;
    const QString charger (const QString &nomFichier);
};

#endif // MyCRYPT_H
