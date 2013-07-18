#include "arme.h"

using namespace std;

Arme::Arme (string nomArme , int attaqueArme , int etatArme) :
        m_nom(nomArme) ,
        m_attaque (attaqueArme) ,
        m_etat (etatArme) {
}

Arme::~Arme () {

}

void Arme::userArme (int usure) {
        m_etat -= usure;
        if (m_etat < 0)
                m_etat = 0;
}

string Arme::getNom () {
        return m_nom;
}

int Arme::getAttaque () {
        return m_attaque;
}

void Arme::initArme (string const& nom , int attaque) {
        m_nom = nom;
        m_attaque = attaque;
}

int Arme::getEtat () {
        return m_etat;
}

void Arme::afficherArme (ostream& flux) const {
        flux << "Arme : " << m_nom << endl;
        flux << "Attaque : " << m_attaque << endl;
        flux << "Etat : " << m_etat << endl;
}

ostream& operator<<(ostream& flux , Arme const& arme) {
        arme.afficherArme (flux);
        return flux;
}
