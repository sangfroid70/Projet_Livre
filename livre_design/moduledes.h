#ifndef MODULEDES_H
#define MODULEDES_H

#include <cstdlib>
#include <QObject>
#include <QDialog>
#include <QString>
#include <QLCDNumber>
#include <QPushButton>
#include <QLayout>
#include <QDebug>
#include <QVector>
#include "des.h"

class ModuleDes : public QDialog {
    Q_OBJECT

public:
    ModuleDes(int nbDes , QWidget *parent=0);
    ~ModuleDes();

signals :
    void resultats (QVector<int> jets);

public slots :
    void lancerDe ();


private:
    void resultatFinal ();

    QString m_texteBouton;      // Texte à afficher dans le bouton
    int m_nbDes;                // nombre de dés
    int m_numeroDe;             // Numéro du dé à jouer
    QPushButton *boutonLancer;  // Bouton du lancement de dé
    QPushButton *boutonQuitter; // explicite ;)
    QVector<Des*> mesDes;         // Tableau de x dés
};

#endif
