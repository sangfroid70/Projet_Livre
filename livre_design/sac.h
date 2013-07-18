#ifndef HEADER_SAC
#define HEADER_SAC

#include <iostream>
#include <string>
#include <vector>
#include "arme.h"

class Sac {
        public:
                Sac ();
                Sac (Sac const & sacACopier);
                ~Sac ();
                bool placeEstVide (int numero) const;

        private:
                //Méthode
                void afficherContenu(std::ostream& flux) const;

                //attributs
                int m_taille;
                std::vector<Arme*> m_place;

friend std::ostream& operator<< (std::ostream& flux , Sac const& leSac);
};

#endif
