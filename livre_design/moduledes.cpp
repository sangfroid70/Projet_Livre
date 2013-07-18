#include "moduledes.h"

ModuleDes::ModuleDes (int nbDes , QWidget *parent)
    : m_nbDes (nbDes) ,
      m_numeroDe (1) ,
      m_texteBouton ("Lancer le d� n�") ,
      QDialog (parent)
{
    // initialisaton des boutons
    boutonLancer = new QPushButton (m_texteBouton + QString::number(m_numeroDe));
    boutonQuitter = new QPushButton ("Quitter");
    boutonQuitter->setEnabled(false);

    // Layout en grille pour l'affichage des boutons et des d�s
    QGridLayout *layoutAffichage = new QGridLayout (this);
    layoutAffichage->addWidget(boutonQuitter , 1 , 0);
    layoutAffichage->addWidget(boutonLancer , 0 , 0);

    // instancier les d�s et les afficher dans le layout
    for (int i = 0 ; i < m_nbDes ; i++ ) {
       mesDes << new Des (1 , this);
       layoutAffichage->addWidget(mesDes[i] , 0 , i+1);
    }

    // Connections boutons
    QObject::connect(boutonLancer , SIGNAL (clicked()) , this , SLOT (lancerDe()));
    QObject::connect(boutonQuitter , SIGNAL (clicked()) , this , SLOT (close()));
}

ModuleDes::~ModuleDes () {
    for (int i ; i < m_nbDes ; i++) {
        delete mesDes[i];
    }
}

void ModuleDes::lancerDe () {
    mesDes[m_numeroDe-1]->stopper(); // Arr�t du d�filement d'un d�
    if (m_numeroDe < m_nbDes) {
        m_numeroDe++;
        boutonLancer->setText(m_texteBouton + QString::number(m_numeroDe));
    }
    else resultatFinal(); // lanc� si on a jet� tous les d�s
}

void ModuleDes::resultatFinal () {
    QVector<int> resultat;              // Tableau d'entiers comprenant les jets de d�s
    for (int i = 0 ; i < m_nbDes ; i++) {
        resultat << mesDes[i]->value();
    }
    boutonLancer->setEnabled(false);
    boutonQuitter->setEnabled(true);
    emit resultats(resultat);           // Envoi d'un signal contenant le tableau de r�sultats
}

