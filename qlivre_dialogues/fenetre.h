#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>

class QAction;

class Fenetre : public QMainWindow
{
    Q_OBJECT

public:
    Fenetre(QWidget *parent = 0);
    ~Fenetre();

public slots :
    void nouveauJeu ();
    void ouvrirJeu ();
    void enregistrerJeu ();
    void aPropos ();

private:
    void creerMenus ();
    void creerActions ();

    QAction *actionAPropos;
    QAction *actionAProposQt;
    QAction *actionNouveau;
    QAction *actionOuvrir;
    QAction *actionEnregistrer;
    QAction *actionQuitter;


};

#endif // FENETRE_H
