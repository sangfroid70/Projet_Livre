#include <iostream>
#include <sstream>

#include "moteur.h"

Moteur::Moteur(Personnage const& perso , QObject *parent) :
    QObject(parent) ,
    m_perso (perso)
{

}

Personnage Moteur::perso() const {
    return m_perso;
}
