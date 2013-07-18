#include <iostream>
#include <string>
#include <vector>
#include "arme.h"

#include "sac.h"

Sac::Sac () :
    m_taille (5) ,
    m_place (m_taille)
{
	for (int i = 0; i < m_taille ; i++) {
		m_place[i] = 0;
	}
}

Sac::Sac (Sac const & sacACopier) :
    m_taille (sacACopier.m_taille)
{
	for (int i = 0; i < m_taille ; i++) {
		m_place[i] = new Arme (*sacACopier.m_place[i]);
	}
}

Sac::~Sac () {
	for (int i = 0; i < m_taille ; i++) {
		delete m_place[i];
		m_place[i] = 0;
	}	
}

void Sac::afficherContenu (std::ostream & flux) const {
        flux << "--------------" << std::endl;
        flux << "contenu du sac" << std::endl;
        flux << "--------------" << std::endl;
        flux << "Taille : " << m_taille << std::endl;
	for (int i = 0 ; i < m_taille ; i++) {
		if (!placeEstVide(i)) {
                        flux << i+1 << " : " << *m_place[i] << std::endl;
                } else flux << "place " << i+1 << " vide" << std::endl;
	}
}

bool Sac::placeEstVide (int numero) const {
	if (m_place[numero] == 0)
		return true;
	else return false;
}

bool Sac::ajouter (Arme * nouvelleArme) {
	for (int i = 0 ; i < 5 ; i++) {
		if (m_place[i] == 0) {
			m_place[i] = nouvelleArme;
			return true;
		}
	}
	return false;
}

Arme* Sac::enlever (int place) {
	Arme *temp = m_place[place];
	m_place[place] = 0;
	return temp;
}

std::string Sac::getNomPlace (int place) {
	if (placeEstVide(place))
		return "Rien";
	else return m_place[place]->getNom();
}

std::ostream& operator<<(std::ostream& flux , Sac const& leSac) {
	leSac.afficherContenu (flux);
	return flux;
}
