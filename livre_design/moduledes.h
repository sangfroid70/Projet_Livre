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

    QString m_texteBouton;      // Texte � afficher dans le bouton
    int m_nbDes;                // nombre de d�s
    int m_numeroDe;             // Num�ro du d� � jouer
    QPushButton *boutonLancer;  // Bouton du lancement de d�
    QPushButton *boutonQuitter; // explicite ;)
    QVector<Des*> mesDes;         // Tableau de x d�s
};

#endif
