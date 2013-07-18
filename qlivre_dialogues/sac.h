#ifndef HEADER_SAC
#define HEADER_SAC

#include <vector>

class Arme;

class Sac {
	public:
		Sac ();
		Sac (Sac const & sacACopier);
		~Sac ();
		bool placeEstVide (int numero) const;
		bool ajouter (Arme * nouvelleArme);
		Arme* enlever (int place);
		std::string getNomPlace (int place);


	private:
                //Méthode
		void afficherContenu(std::ostream& flux) const;
		
		//attributs
		int m_taille;
		std::vector<Arme*> m_place;

friend std::ostream& operator<< (std::ostream& flux , Sac const& leSac);
};

#endif
