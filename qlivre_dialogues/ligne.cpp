#include <QMessageBox>
#include <QAction>
#include <QMenuBar>
#include <QMenu>

#include "moteur.h"
#include "accueil.h"
#include "ecran.h"

#include "ligne.h"

Ligne::Ligne (QString titre, Style style, int nbDes, QWidget *parent) :
    QWidget(parent) ,
    m_titre (titre) ,
    m_style (style) ,
    m_nbDes (nbDes)
{
    layout = new QHBoxLayout (this);

    intituler ();

    switch (m_style) {
    case Texte:
        creerLineEdit();
        break;
    case Nombres:
        creerBoutonDes();
        break;
    }

    creerCheckBox();
}

void Ligne::intituler() {
    if (m_nbDes > 0) {
        QString singulierPluriel = (m_nbDes > 1)? "s)" : ")";
        m_titre += " (" + QString::number(m_nbDes) + " dé" + singulierPluriel;
    }
    QLabel *label = new QLabel (m_titre , this);
    layout->addWidget(label);
}

void Ligne::creerLineEdit() {
    zoneTexte = new QLineEdit (this);
    layout->addWidget(zoneTexte);
    QObject::connect (zoneTexte , SIGNAL(textChanged(QString)) , this , SLOT (checker()));
}

void Ligne::creerBoutonDes() {
    affichage = new TableauChiffres (m_nbDes , this);
    bouton = new QPushButton ("Lancer" , this);
    layout->addWidget(affichage);
    layout->addWidget(bouton);
    QObject::connect (bouton , SIGNAL (clicked()) , this , SLOT (lancer()));
}

void Ligne::creerCheckBox() {
    checkBox = new QCheckBox (this);
    checkBox->setDisabled(true);
    checkBox->setChecked(false);
    layout->addWidget(checkBox);
}

void Ligne::lancer() {
    ModuleDes *monDe = new ModuleDes(m_nbDes , this);
    if (monDe->exec() == QDialog::Accepted) {
        affichage->setChiffres (monDe->resultats());
        affichage->afficher(TableauChiffres::Tout);
        delete bouton;
        checker();
    }
}

void Ligne::checker() {
    bool ok = false;
    switch (m_style) {
    case Texte:
        if (!zoneTexte->text().isEmpty()) {
            ok = true;
        }
        break;
    case Nombres:
        ok = true;
        break;
    }
    checkBox->setChecked(ok);
}

bool Ligne::estValide() {
    return checkBox->isChecked();
}

QString Ligne::text() {
    if (m_style == Texte) {
        return zoneTexte->text();
    } else return NULL;
}

int Ligne::value () {
    if (m_style == Nombres) {
        return affichage->total();
    } else return 0;
}
