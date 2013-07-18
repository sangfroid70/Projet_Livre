#include "personnage.h"

using namespace std;

Personnage::Personnage (string nom) :
        m_nom(nom),
        m_vie(100),
        m_mana(50),
        m_attaque(7)
{
        m_arme = new Arme();
        m_sac = new Sac ();
}

Personnage::Personnage (Personnage const & joueurACopier) :
        m_nom (joueurACopier.m_nom),
        m_vie (joueurACopier.m_vie),
        m_mana (joueurACopier.m_mana),
        m_attaque (joueurACopier.m_attaque)
{
        m_arme = new Arme (*joueurACopier.m_arme);
        m_sac = new Sac (*joueurACopier.m_sac);
}

Personnage::~Personnage () {
        delete m_arme;
}

///////////////////////////    Setters    ///////////////////////////
void Personnage::init (int vie , int mana , int attaque , string const& nomArme , int attaqueArme) {
        m_vie = vie;
        m_mana = mana;
        m_attaque = attaque;
        m_arme->initArme (nomArme , attaqueArme);
}

void Personnage::setNom (string nom) {
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

///////////////////////////    Getters    ///////////////////////////
bool Personnage::estVivant () const {
        if (m_vie <= 0)
                return false;
        else
                return true;
}

string Personnage::getNom() const {
        return m_nom;
}

int Personnage::getDegats () const {
        return m_attaque + m_arme->getAttaque();
}

void Personnage::afficherEtat(ostream& flux) const {
        flux << "-- " << m_nom     << " --" <<endl;
        flux << "Vie :     " << m_vie     << endl;
        flux << "Mana :    " << m_mana    << endl;
        flux << "Attaque : " << m_attaque << endl;
        flux << *m_arme << endl;
        flux << *m_sac << endl;
}

///////////////////////////   Actions   ///////////////////////////
void Personnage::recevoirDegats (int nbDegats) {
        m_vie -= nbDegats;
        if (m_vie < 0)
                m_vie = 0;
}

void Personnage::attaquer (Personnage &cible) {
        if (estVivant())
                cible.recevoirDegats (m_arme->getAttaque() + m_attaque);
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



ostream& operator<<(ostream &flux , Personnage const& personne) {
        personne.afficherEtat(flux);
        return flux;
}
