#ifndef HEADER_PERSONNAGE
#define HEADER_PERSONNAGE

#include <string>
#include <iostream>

class Sac;
class Arme;

class Personnage {
	public:
                // Méthodes
		Personnage(std::string nom = "Inconnu");
		Personnage(Personnage const& joueurACopier);
		~Personnage ();
		void init (
				int vie ,
				int mana ,
				int attaque ,
				std::string const& nomArme ,
				int attaqueArme); 
		void recevoirDegats (int nbDegats);
		bool attaquer (Personnage &cible);
		void boirePotionDeVie (int nbPotion);
		void changerArme (Arme *nouvelleArme);
		void echangerArme (Personnage & cible);
		bool estVivant () const;
		void setNom (std::string nom);
		void setVie (int vie);
		void setMana (int mana);
		void setAttaque (int attaque);
		int getDegats ();
		int getVie ();
		int getMana();
		int getAttaque ();
		std::string getNomArme ();
		std::string getNom ();


	private:
                //Méthodes
		void afficherEtat(std::ostream& flux) const;

		// attributs
		std::string m_nom;
		int m_vie;
		int m_mana;
		int m_attaque;
		Sac *m_sac;
		Arme *m_arme;


		friend std::ostream& operator<<(std::ostream &flux , Personnage const &personnage);
};

#endif
