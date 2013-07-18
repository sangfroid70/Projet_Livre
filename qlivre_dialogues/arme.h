#ifndef HEADER_ARME
#define HEADER_ARME

#include <iostream>
#include <string>

class Arme {
public:
    Arme (std::string nomArme = "Epée Rouillée" , int attaqueArme = 5 , int etatArme = 100 );
    ~Arme ();

    void userArme (int usure);
    std::string getNom ();
    int getAttaque ();
    int getEtat ();
    void initArme (std::string const& nomArme , int attaque);

private:
    // Méthode
    void afficherArme (std::ostream & flux) const;

    // Attributs
    std::string m_nom;
    int m_attaque;
    int m_etat;

    friend std::ostream& operator<<(std::ostream& flux , Arme const& arme);
};	


#endif
