#include "mycrypt.h"

MyCrypt::MyCrypt (const QString &nomFichier) :
    m_nomFichier (nomFichier) ,
    m_nomFichierSortie ("_"+nomFichier)
{

}

MyCrypt::~MyCrypt () {
}

const QString MyCrypt::chargerDecrypter() {
    //return decrypter(charger (m_nomFichierSortie));
    return charger(m_nomFichierSortie);
}

void MyCrypt::sauvegarderCrypter() {
    QString chaine (charger (m_nomFichier));
    //std::ofstream monFichier (m_nomFichierSortie.c_str() , std::ios::out);
    QFile monFichier (m_nomFichierSortie);
    if (monFichier.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out (&monFichier);
        //out << crypter(chaine);
        out << chaine;
        monFichier.close();
    }
}

const QString MyCrypt::charger(const QString &nomFichier) {
    QString chaine;
    QFile monFichier (nomFichier);
    if (!monFichier.open(QIODevice::ReadOnly | QIODevice::Text))
        return "";
    //std::ifstream monFichier (nomFichier.c_str() , std::ios::in);
    QTextStream in (&monFichier);
    while (!in.atEnd()) {
         chaine += in.readLine();
    }
    monFichier.close();
    return chaine;
}

/*QString MyCrypt::crypter(const QString &chaineEntree , int decalage) {
    QString chaineSortie = chaineEntree;
    for (int i = 0 ; i < chaineEntree.size() ; i++) {
        if (chaineEntree[i] >= 32 && chaineEntree[i] <= 255) {
            chaineSortie[i] = (chaineEntree[i]+decalage-32)%(255-32)+ 32;
        }
        else chaineSortie[i] = chaineEntree[i];
    }
    return chaineSortie;
}

QString MyCrypt::decrypter(const QString &chaineEntree , int decalage) {
    decalage *= -1;
    QString chaineSortie = chaineEntree;
    for (int i = 0 ; i < chaineEntree.size() ; i++) {
        if (chaineEntree[i] >= 32 && chaineEntree[i] <= 255) {
            chaineSortie[i] = (chaineEntree[i]+decalage-32)%(255-32)+ 32;
        }
        else chaineSortie[i] = chaineEntree[i];
    }
    return chaineSortie;
}*/
