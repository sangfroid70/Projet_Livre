#include "arme.h"

Arme::Arme (std::string nomArme , int attaqueArme , int etatArme) :
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

std::string Arme::getNom () {
	return m_nom;
}

int Arme::getAttaque () {
	return m_attaque;
}

void Arme::initArme (std::string const& nom , int attaque) {
	m_nom = nom;
	m_attaque = attaque;
}

int Arme::getEtat () {
	return m_etat;
}

void Arme::afficherArme (std::ostream& flux) const {
        flux << "Arme : " << m_nom << std::endl;
        flux << "Attaque : " << m_attaque << std::endl;
        flux << "Etat : " << m_etat << std::endl;
}

std::ostream& operator<<(std::ostream& flux , Arme const& arme) {
	arme.afficherArme (flux);
	return flux;
}
