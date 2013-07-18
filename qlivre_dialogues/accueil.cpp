#include "ligne.h"
#include "personnage.h"
#include "arme.h"
#include "tableauchiffres.h"
#include <QObject>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QDebug>

#include "accueil.h"


Accueil::Accueil (QWidget *parent) :
    QDialog(parent) ,
    m_ligne (-1)
{
    setMinimumSize(300,200);

    QWidget *ongletNouveau = new QWidget (this);

    //// Créations du tabWidget et des onglets
    QTabWidget *tabWidget = new QTabWidget(this);
    tabWidget->addTab(ongletNouveau , "Nouvelle partie");

    //// Création des Widgets de l'onglet Nouveau
    nom = new Ligne ("Nom du joueur" , Ligne::Texte , 0 , this);
    vie = new Ligne ("Vie" , Ligne::Nombres , 1 , this);
    attaque = new Ligne ("Attaque" , Ligne::Nombres , 3 , this);
    magie = new Ligne ("Magie" , Ligne::Nombres , 2 , this);

    //// Boutons de la boite de dialogue
    boutonsDialogue = new QDialogButtonBox (QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    ///////////////  Layouts ///////////////////////////////
    layoutOngletNouveau = new QVBoxLayout (ongletNouveau);
    layoutOngletNouveau->addWidget(nom);
    layoutOngletNouveau->addWidget(vie);
    layoutOngletNouveau->addWidget(attaque);
    layoutOngletNouveau->addWidget(magie);

    layout = new QVBoxLayout (this);
    layout->addWidget (tabWidget);
    layout->addWidget(boutonsDialogue);

    ///////////////// Connexions ////////////////////////////////////
    QObject::connect (boutonsDialogue , SIGNAL (accepted()) , this , SLOT (accepter()));
    QObject::connect (boutonsDialogue , SIGNAL (rejected()) , this , SLOT (reject()));

}

////////////////////////// Appuie sur OK /////////////////////////
void Accueil::accepter() {
    if (
        nom->estValide() &&
        vie->estValide() &&
        attaque->estValide() &&
        magie->estValide()
        )
    {
        accept();
    }
}

/////////////////////////  Renvoyer un type Personnage ///////////////////
Personnage Accueil::creerPerso() const {
    Personnage perso (nom->text().toStdString());
    perso.setVie(vie->value());
    perso.setAttaque(attaque->value());
    perso.setMana(magie->value());
    perso.changerArme(new Arme ("Sabre"));
    return perso;
}
