#include <QLCDNumber>
#include <QPushButton>
#include <QGridLayout>

#include "des.h"

#include "moduledes.h"

ModuleDes::ModuleDes (int nbDes , QWidget *parent) :
      QDialog (parent) ,
      m_nbDes (nbDes) ,
      m_numeroDe (1) ,
      m_total (0) ,
      m_texteBouton ("Lancer le dé n°")
{
    // initialisaton des boutons
    boutonLancer = new QPushButton (m_texteBouton + QString::number(m_numeroDe));
    boutonQuitter = new QPushButton ("Quitter");
    boutonQuitter->setEnabled(false);

    // Layout en grille pour l'affichage des boutons et des dés
    QGridLayout *layoutAffichage = new QGridLayout (this);
    layoutAffichage->addWidget(boutonQuitter , 1 , 0);
    layoutAffichage->addWidget(boutonLancer , 0 , 0);

    // instancier les dés et les afficher dans le layout
    for (int i = 0 ; i < m_nbDes ; i++ ) {
       mesDes << new Des (1 , this);
       layoutAffichage->addWidget(mesDes[i] , 0 , i+1);
    }

    // Connections boutons
    QObject::connect(boutonLancer , SIGNAL (clicked()) , this , SLOT (lancerDe()));
    QObject::connect(boutonQuitter , SIGNAL (clicked()) , this , SLOT (accept()));
}

ModuleDes::~ModuleDes () {
    for (int i = 0 ; i < m_nbDes ; i++) {
        delete mesDes[i];
    }
}

void ModuleDes::lancerDe () {
    if (m_numeroDe <= m_nbDes) {
        mesDes[m_numeroDe-1]->stopper(); // Arrêt du défilement d'un dé
        m_resultats << mesDes[m_numeroDe-1]->value();
        m_total += m_resultats[m_numeroDe-1];
        if (m_numeroDe < m_nbDes) {
            boutonLancer->setText(m_texteBouton + QString::number(m_numeroDe+1));
        }
        if (m_numeroDe == m_nbDes) {
            boutonLancer->setEnabled(false);
            boutonQuitter->setEnabled(true);
        }
        m_numeroDe++;
    }
}

QVector<int> ModuleDes::resultats() const {
    return m_resultats;
}

int ModuleDes::total () {
    return m_total;
}
