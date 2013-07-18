#include <QApplication>
#include <QMessageBox>
#include <QAction>
#include <QMenuBar>
#include <QMenu>

#include "moteur.h"
#include "accueil.h"
#include "ecran.h"

#include "fenetre.h"

Fenetre::Fenetre(QWidget *parent)
    : QMainWindow(parent) {
    creerActions();
    creerMenus();

    setMinimumSize(640,480);
    setWindowTitle("Qt dont vous �tes le h�ros");
}

Fenetre::~Fenetre() {

}

void Fenetre::creerActions () {
    actionNouveau = new QAction ("&Nouveau Jeu" , this);
    actionNouveau->setShortcut(QKeySequence("Ctrl+N"));
    connect(actionNouveau , SIGNAL(triggered()) , this , SLOT (nouveauJeu ()));

    actionOuvrir = new QAction ("&Ouvrir partie" , this);
    actionOuvrir->setShortcut(QKeySequence("Ctrl+O"));
    connect(actionOuvrir , SIGNAL(triggered()) , this , SLOT (ouvrirJeu ()));

    actionEnregistrer = new QAction ("&Enregistrer partie" , this);
    actionEnregistrer->setShortcut(QKeySequence("Ctrl+S"));
    connect(actionEnregistrer , SIGNAL(triggered()) , this , SLOT (enregistrerJeu ()));

    actionQuitter = new QAction ("&Quitter" , this);
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    connect (actionQuitter , SIGNAL (triggered()) , qApp , SLOT (quit()));

    actionAPropos = new QAction("&A propos...", this);
    connect(actionAPropos, SIGNAL(triggered()), this, SLOT(aPropos()));

    actionAPropos->setShortcut(QKeySequence::HelpContents);
    actionAProposQt = new QAction("A propos de &Qt...", this);
    connect(actionAProposQt, SIGNAL(triggered()), qApp , SLOT(aboutQt()));
}

void Fenetre::creerMenus () {
    QMenu *menuFichier = menuBar()->addMenu ("&Fichier");
    menuFichier->addAction (actionNouveau);
    menuFichier->addAction (actionOuvrir);
    menuFichier->addAction(actionEnregistrer);
    menuFichier->addSeparator();
    menuFichier->addAction(actionQuitter);

    QMenu *menuAide = menuBar()->addMenu ("&Aide");
    menuAide->addAction(actionAPropos);
    menuAide->addAction(actionAProposQt);
}

void Fenetre::nouveauJeu () {
    Accueil accueil (this);
    if (accueil.exec() == QDialog::Accepted) {
        Moteur moteur (accueil.creerPerso());
        Ecran *monEcran = new Ecran(moteur.perso());
        setCentralWidget(monEcran);

        /*std::ostringstream texte;
        texte << *moteur.perso();
        qDebug () << QString::fromStdString(texte.str());*/
    }

}

void Fenetre::ouvrirJeu () {

}

void Fenetre::enregistrerJeu () {

}

void Fenetre::aPropos () {
    QMessageBox::about(this , "A propos de ce programme" ,
                       "Ce programme est un test de d�veloppement d'un livre dont vous �tes le h�ros � base de Qt\nil a �t� d�velopp� par Zo� et Fran�ois"
                       );
}
