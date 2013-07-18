#include "sac.h"

using namespace std;

Sac::Sac () : m_taille (5) , m_place (m_taille) {
        for (int i = 0; i < m_taille ; i++) {
                m_place[i] = 0;
        }
}

Sac::Sac (Sac const & sacACopier) : m_taille (sacACopier.m_taille) {
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

void Sac::afficherContenu (ostream & flux) const {
        flux << "--------------" << endl;
        flux << "contenu du sac" << endl;
        flux << "--------------" << endl;
        flux << "Taille : " << m_taille << endl;
        for (int i = 0 ; i < m_taille ; i++) {
                if (!placeEstVide(i)) {
                        flux << i+1 << " : " << *m_place[i] << endl;
                } else flux << "place " << i+1 << " vide" << endl;
        }
}

bool Sac::placeEstVide (int numero) const {
        if (m_place[numero] == 0)
                return true;
        else return false;
}


ostream& operator<<(ostream& flux , Sac const& leSac) {
        leSac.afficherContenu (flux);
        return flux;
}
