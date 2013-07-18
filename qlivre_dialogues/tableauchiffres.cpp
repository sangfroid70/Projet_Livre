#include "tableauchiffres.h"

#include <QLabel>

TableauChiffres::TableauChiffres(int taille , QWidget *parent) :
    QLineEdit (parent) ,
    m_chiffres(taille),
    m_taille (taille),
    m_texte ("") ,
    m_affichage (Tout)
{
    setDisabled(true);
}

TableauChiffres::TableauChiffres(QVector<int> const& chiffres , QWidget *parent) :
    QLineEdit(parent) ,
    m_chiffres (chiffres) ,
    m_taille (chiffres.size()) ,
    m_texte ("") ,
    m_affichage (Tout)
{
    setDisabled(true);
}

void TableauChiffres::setChiffres(const QVector<int> &chiffres) {
    effacer();
    m_chiffres.clear();
    m_chiffres = chiffres;
}

int TableauChiffres::total () {
    int total(0);
    for (int i = 0 ; i <m_taille ; i++) {
        total += m_chiffres[i];
    }
    return total;
}

void TableauChiffres::totalLabel () {
    m_texte += QString::number(total());
}

void TableauChiffres::toutLabel () {
    chiffresLabel();
    m_texte += " = ";
    totalLabel();
}

void TableauChiffres::chiffresLabel() {
    for (int i = 0 ; i < m_taille ; i++) {
       m_texte += QString::number(m_chiffres[i]);
        if (i+1 < m_taille) {
            m_texte += " + ";
        }
    }
}

void TableauChiffres::afficher (Affichage affichage) {
    setAffichage(affichage);
    switch (m_affichage) {
    case Tout:
    case Defaut:
        toutLabel ();
        break;
    case Chiffres:
        chiffresLabel();
        break;
    case Total:
        totalLabel();
        break;
    }
    setText(m_texte);
}

void TableauChiffres::effacer () {
    clear();
    m_texte.clear();
}

void TableauChiffres::setAffichage(Affichage affichage) {
    if (affichage != Defaut)
        m_affichage = affichage;
    else m_affichage = Tout;
}
