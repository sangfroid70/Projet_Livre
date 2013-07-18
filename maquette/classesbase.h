#ifndef clas_point_h
#define clas_point_h

#include <iostream>
#include <QtGui>

using namespace std;

// INFORMATIONS RENVOYEES A LA FIN D'UN COMBAT//
struct rescombat
{
	int respv; //les pv restants à la fin du combat
	int dead; // 0->VOUS êtes mort / 1->le monstre est mort / -1->il n'y a pas eu de monstre à combattre
};

//OBJETS ET ARMES//
class objet{

	string nom_objet;

	public :
	objet();
	string get_nom_objet();
	void changer_objet(string name);
	void affiche_objet();

};


class arme : public objet{

	int degats;

	public :
	arme();
	int get_degats();
	void changer_arme(string name,int d);
	void affiche_arme();

};

//JOURNAL//
class journal{

	string* descr; //la description du paragraphe (en un mot) donnée par le joueur
	int* para_asso; //le paragraphe associé à cette description
	
	int nb_entrees;

	public :
	journal();
	int get_nb_entrees();
	string get_descr(int i);
	int get_para_asso(int i);
	void ajout_descr_para(string d, int p);
	void affiche_entrees();

};

//PERSONNAGES//
class personnage{

	string nom;
	int pv;
	arme arme_equipee;

	public :
	personnage();
	string get_name();
	void changer_pv(int a);
	int get_pv();
	arme get_armeequip();
	void changer_arme_equipee(arme a);
	void changer_nom(string n);
	void affiche_personnage();
};

class monstre : public personnage{

	string descr; //la description du monstre
	string parasuiv; //le paragraphe où il faut se rendre si le monstre est tué (rappel pratique pour éviter de devoir réafficher le texte)

	public :
	monstre();
	string get_descr();
	void changer_descr(string d);
	void changer_para_suiv(string p);
	string get_para_suiv();
	void affiche_monstre();

};

class vous : public personnage{


	objet* tab; //votre inventaire
	int nb_objets; //le nombre d'objets en votre possession

	public :
	vous();
	objet get_tab(int i);
	int get_nb_objets();
	void erase_tab(string nom); //supprime de l'inventaire l'objet dont le nom est passé en argument
	void ajout_objet(objet o);
	void affiche_vous();

};

//QT TEXTE & DE & REGLES & MENU//
class AfficherTexte : public QWidget {

    Q_OBJECT
    QLabel *texte;
    QPushButton *bouton;
    QFile file;

    public slots:
    void affichetxt(string s); //affiche une fenêtre contenant le texte du paragraphe concerné

};

class AfficherDe : public QWidget {

    Q_OBJECT
    QLabel *texte2;
    QPushButton *bouton2;
    QFile file2;

    public slots:
    AfficherDe* affichede(); //affiche une fenêtre proposant de lancer un dé

};

class AfficherRegles : public QWidget
{
    Q_OBJECT
 
    public:
    AfficherRegles();
 
    public slots:
    AfficherTexte* ouvrirDialogue();//affiche une série de fenêtres proposant de lire les Règles du Jeu
 
    private:
    QPushButton *m_boutonDialogue;
};

class AfficherMenu : public QWidget
{
    Q_OBJECT
 
    public:
    AfficherMenu();
 
    public slots:
    int ouvrirMenu(); //affiche un menu offrant diverses possibilités (sauvegarder, charger, gestion du Journal et du Profil...)
    int ouvrirMenuDepart();//affiche le menu de départ
    int choisiremplacement();//propose 3 emplacements
 
    private:
    QPushButton *m_boutonDialogue2;
};

#endif
