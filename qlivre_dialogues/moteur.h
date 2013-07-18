#ifndef MOTEUR_H
#define MOTEUR_H

#include <QObject>
#include "personnage.h"

class Moteur : public QObject
{
    Q_OBJECT
public:
    explicit Moteur(Personnage const& perso , QObject *parent = 0);
    Personnage perso() const ;

public slots:


private:
    Personnage m_perso;
};

#endif // MOTEUR_H
