#ifndef HEADER_PERSONNAGE
#define HEADER_PERSONNAGE

#include <string>
#include <iostream>
#include <QTextStream>
#include <QDataStream>
#include "arme.h"
#include "sac.h"

class Personnage {
public:
    // Méthodes
    Personnage(std::string nom = "Inconnu");
    Personnage(Personnage const& joueurACopier);
    ~Personnage ();

    void init (
        int vie,
        int mana,
        int attaque,
        std::string const& nomArme,
        int attaqueArme);

    void recevoirDegats (int nbDegats);
    void attaquer (Personnage &cible);
    void boirePotionDeVie (int nbPotion);
    void changerArme (Arme *nouvelleArme);
    void echangerArme (Personnage & cible);
    void setNom (std::string nom);
    void setVie (int vie);
    void setMana (int mana);
    void setAttaque (int attaque);
    bool estVivant () const;
    int getDegats () const;
    std::string getNom () const;
    void afficherEtat(std::ostream& flux) const;


private:
    // attributs
    std::string m_nom;
    int m_vie;
    int m_mana;
    int m_attaque;
    Sac *m_sac;
    Arme *m_arme;


    friend std::ostream& operator<<(std::ostream &flux , Personnage const &personnage);
    //friend QDataStream& operator<<(QDataStream &flux , Personnage const &personnage);
};

#endif
