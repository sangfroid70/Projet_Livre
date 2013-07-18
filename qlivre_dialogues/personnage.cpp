#include "arme.h"
#include "sac.h"

#include "personnage.h"

// Constructeurs
Personnage::Personnage (std::string nom) :
	m_nom(nom),
	m_vie(100),
	m_mana(50),
	m_attaque(7) 
{
        m_arme = new Arme;
        //m_sac = new Sac;
}

Personnage::Personnage (Personnage const & joueurACopier) :
	m_nom (joueurACopier.m_nom),
	m_vie (joueurACopier.m_vie),
	m_mana (joueurACopier.m_mana),
	m_attaque (joueurACopier.m_attaque)
{
	m_arme = new Arme (*joueurACopier.m_arme);
        //m_sac = new Sac (*joueurACopier.m_sac);
}

// Destructeur
Personnage::~Personnage () {
	delete m_arme;
        //delete m_sac;
}

// Initialisation
void Personnage::init (int vie , int mana , int attaque , std::string const& nomArme , int attaqueArme) {
	m_vie = vie;
	m_mana = mana;	
	m_attaque = attaque;
	m_arme->initArme (nomArme , attaqueArme);
}

//////////////////////////////////////////// Méthodes ////////////////////////////////////////
void Personnage::recevoirDegats (int nbDegats) {
	m_vie -= nbDegats;
	if (m_vie < 0)
		m_vie = 0;
}

bool Personnage::attaquer (Personnage &cible) {
	if (cible.estVivant()) {
		cible.recevoirDegats (m_arme->getAttaque() + m_attaque);
		return true;
	} else return false;
}

void Personnage::boirePotionDeVie (int nbPotion) {
	m_vie += nbPotion;
	if (m_vie >= 100)
		m_vie = 100;
}

void Personnage::changerArme (Arme *nouvelleArme) {
	m_arme = nouvelleArme; 
	
}

void Personnage::echangerArme (Personnage& cible) {
	Arme *temp(m_arme);
	m_arme = cible.m_arme;
	cible.m_arme = temp;
}

bool Personnage::estVivant () const {
	if (m_vie <= 0)
		return false;
	else
		return true;
}

void Personnage::afficherEtat(std::ostream& flux) const {
        if (!estVivant()) flux << "+++ Décédé +++" << std::endl;
        flux << "-- " << m_nom     << " --" <<std::endl;
        flux << "Vie :     " << m_vie     << std::endl;
        flux << "Mana :    " << m_mana    << std::endl;
        flux << "Attaque : " << m_attaque << std::endl;
        flux << *m_arme << std::endl;
        //flux << *m_sac << std::endl;
}


//////////////////////////////////////////////// Accesseurs /////////////////////////////////////////
void Personnage::setNom (std::string nom) {
	m_nom = nom;
}

void Personnage::setVie (int vie) {
	m_vie = vie;
}

void Personnage::setMana (int mana) {
	m_mana = mana;
}

void Personnage::setAttaque (int attaque) {
	m_attaque = attaque;
}

std::string Personnage::getNom() {
	return m_nom;
}

int Personnage::getDegats () {
	return m_attaque + m_arme->getAttaque();
}

int Personnage::getVie() {
	return m_vie;
}

int Personnage::getMana () {
	return m_mana;
}

int Personnage::getAttaque () {
	return m_attaque;
}

std::string Personnage::getNomArme () {
	return m_arme->getNom();
}

///////////////////////////////////////////////////////////// Surcharge opérateur <<    /////////////////////////////
std::ostream& operator<<(std::ostream &flux , Personnage const& personne) {
	personne.afficherEtat(flux);
	return flux;
}
