#include <iostream>
using namespace std;

#include "classesbase.h"
#include "combat.h"

// OBJETS //
objet::objet()
{nom_objet="vide";}

string objet::get_nom_objet()
{ return nom_objet; }

void objet::changer_objet(string name)
{nom_objet=name;}

void objet::affiche_objet()
{cout<<"- "<<nom_objet<<endl;}


// ARME //
arme::arme()
{ objet();
  degats=0; }

int arme::get_degats()
{ return degats; }


void arme::changer_arme(string name, int d)
{	changer_objet(name);
	degats=d; }

void arme::affiche_arme()
{	affiche_objet();
	cout<<"    Dégâts : "<<degats<<endl; }

// JOURNAL //

journal::journal()
{
	descr=new string[100];
	for (int i=0;i<99;i++) {descr[i]="ligne vide";}

	para_asso=new int[100];
	for (int i=0;i<99;i++) {para_asso[i]=-1;}
	
	nb_entrees=0;

	}

int journal::get_nb_entrees()
{ return nb_entrees; }

string journal::get_descr(int i)
{ return descr[i]; }

int journal::get_para_asso(int i)
{ return para_asso[i]; }

void journal::ajout_descr_para(string d, int p)
{
	int compt=0;

	if (nb_entrees<100)
	{

	for (int i=0;i<99;i++) {if (get_para_asso(i) == p) {compt++; descr[i]=d;}
	// grâce �  compt, on ne peut pas avoir deux occurences du même paragraphe (le mot-clé est automatiquement remplacé en cas d'inscriptions multiples)
	
	}

	if (compt==0)
	 {descr[nb_entrees]=d;
	 para_asso[nb_entrees]=p;
	  nb_entrees++; }

	 }

	else {cout<<"plus de place !"<<endl;}
}


void journal::affiche_entrees()
{
	cout<<endl;
	cout<<"	"<<"JOURNAL"<<endl;
	cout<<endl;

	for (int i=0;i<99;i++)
	{	if (descr[i] != "ligne vide")
		{cout<<i+1<<")"<<" "<<descr[i]<<" au §"<<para_asso[i]<<endl;}	}

	cout<<endl;
	cout<<endl;
}

// PERSONNAGE //

personnage::personnage()
{	nom="unknown";

	pv=0;

	arme_equipee=arme();
 }

string personnage::get_name()
{ return nom; }

void personnage::changer_nom(string n)
{ nom=n; }

void personnage::changer_pv(int a)
{  pv=a; }

int personnage::get_pv()
{ return pv; }

void personnage::changer_arme_equipee(arme a) // si le joueur change d'arme, c'est inscrit sur la console (sauf �  la création du personnage)
{ 	
	
	if (arme_equipee.get_degats() != -1)
	
        {if ((a.get_degats() >= arme_equipee.get_degats() || (a.get_degats() == -1)) ) //l'arme equip�e est automatiquement celle avec le plus haut d�g�t, sauf pour l'arme-punition Goudron_et_Plumes qui ne peut �tre remplacée
	{arme_equipee=a;
	 if (nom == "VOUS" && a.get_nom_objet() != "vide") {cout<<endl;cout<<"Vous vous équipez de "<<a.get_nom_objet()<<" (+"<<a.get_degats()<<") "<<" !"<<endl;}
	 }}
	
	  }

arme personnage::get_armeequip()
{ return arme_equipee; }

void personnage::affiche_personnage()
{
	cout<<endl;
	cout<<"Nom : "<<nom<<endl;
	cout<<endl;
	cout<<"PV : "<<pv<<endl;
	cout<<"Arme : "<<endl;
	cout<<"  ";
	arme_equipee.affiche_arme();
	cout<<endl;
}



// MONSTRE //

monstre::monstre()
{	personnage();
	descr="rien";
	parasuiv="aucun";  }

string monstre::get_descr()
{ return descr; }

void monstre::changer_descr(string d)
{ descr=d; }

void monstre::affiche_monstre()
{
	affiche_personnage();
	cout<<descr<<endl;
	cout<<endl;
}

void monstre::changer_para_suiv(string p)
{ parasuiv=p; }
	
string monstre::get_para_suiv()
{ return parasuiv; }

// VOUS //

vous::vous()	//votre "Feuille de Personnage" est créée aléatoirement
{
 personnage();

 int res=lancer_de() + lancer_de();	// vos PV sont déterminés par (un lancer de deux dés)x4
 res=4*res;
 if (res<12) {res=12;}	//vos PV peuvent initialement aller de (1+1)x4=8 �  (6+6)x4=48 mais le nombre minimum de est fixé �  12 (sinon le jeu est trop difficile)

 changer_nom("VOUS");
 changer_pv(res);
 nb_objets=0;
 tab=new objet[100];
 for (int i=0;i<100;i++) {tab[i]=objet();} //la classe "objet" peut être vue comme un emplacement réservé �  un objet ; votre inventaire possède 100 emplacements vides (car initialisés avec le constructeur d'objet) que l'on remplira au fur et �  mesure
 }

objet vous::get_tab(int i)
{  return tab[i]; }

int vous::get_nb_objets()
{ return nb_objets;}

void vous::erase_tab(string nom)
{
	int indice=-1;
	for (int j=0;j<100;j++) { if (tab[j].get_nom_objet() == nom) {indice=j;} }
	if (indice != -1)
	{for (int k=indice;k<=nb_objets;k++) { tab[k]=tab[k+1]; }
	tab[99]=objet();
	nb_objets--;}
	//seul un objet possédé peut être supprimé de l'inventaire ; sinon, le bonus "TRICHEUR" se met en route et vous pénalise
	else {cout<<" TYR : *Vous, l�  ! Oui, VOUS ! Vous avez triché, pas vrai ?* "<<endl;
		  cout<<" TYR : *Et vous savez comment on traite les tricheurs ?* "<<endl;
		  arme plumes=arme();
		  plumes.changer_arme("Plumes_et_Goudron",-1);
		  changer_arme_equipee(plumes);
		  changer_nom("TRICHEUR");
		  affiche_vous();}
}

void vous::ajout_objet(objet o)
{
   int deja=0;
   if (o.get_nom_objet() != "vide") //on vérifie si l'objet existe
	{	
		if (o.get_nom_objet() != "Potion") // si l'objet est déj�  dans l'inventaire, on ne le rajoute pas (sauf si c'est une Potion)
			{  for (int i=0;i<100;i++)
				{ if (tab[i].get_nom_objet() == o.get_nom_objet())
					{deja++;} } }
		if (deja==0)
		  {tab[nb_objets]=o; nb_objets++;} 
	}
}

void vous::affiche_vous()
{
	cout<<endl;
	affiche_personnage();
	cout<<"Inventaire : "<<endl;
	for (int i=0;i<100;i++) { if (tab[i].get_nom_objet() != "vide")
								{cout<<"  ";
								tab[i].affiche_objet();}}
	cout<<endl;
}


// AFFICHER TEXTE //

//une partie du code Qt provient du tutoriel Qt du Site du Zéro

void AfficherTexte::affichetxt(string s) // Merci �  Jonathan et Xavier pour leur aide dans la partie Qt
{
    
	QFile file(s.c_str());

	setFixedSize(750,900);
	
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream out(&file);
    texte = new QLabel(out.readAll()+ "\n",this);
    
    bouton = new QPushButton("ok",this);
	bouton->move(700,850);
	
    QObject::connect(bouton,SIGNAL(clicked()),qApp,SLOT(quit()));
    
    
}

// AFFICHER DE //

AfficherDe* AfficherDe::affichede()
{

   QFile file2("de.txt");

	setFixedSize(100,110);
	
    file2.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream out2(&file2);
    texte2 = new QLabel(out2.readAll()+ "\n",this);
    
    bouton2 = new QPushButton("Lancer",this);
	bouton2->move(10,60);
	
    QObject::connect(bouton2,SIGNAL(clicked()),qApp,SLOT(quit()));
    
    return this;
    

}

// AFFICHER REGLES //

AfficherRegles::AfficherRegles() : QWidget()
{
    setFixedSize(230, 120);
 
    m_boutonDialogue = new QPushButton("Ouvrir la boîte de dialogue", this);
    m_boutonDialogue->move(40, 50);
 
    QObject::connect(m_boutonDialogue, SIGNAL(clicked()), this, SLOT(ouvrirDialogue()));
}
 
AfficherTexte* AfficherRegles::ouvrirDialogue()
{
	AfficherTexte* aff=new AfficherTexte();
    int reponse = QMessageBox::question(this, "TYR", "Dites, vous voulez lire les Regles du Jeu ?", QMessageBox::Yes | QMessageBox::No);
 
    if (reponse == QMessageBox::Yes)
    {    
		
		aff->affichetxt("regles.txt");
    
    }
    
    else if (reponse == QMessageBox::No)
    {
        QMessageBox::critical(this, "TYR", "Dommage pour VOUS !");
		aff=NULL;
    }
    
    return aff;
}

// AFFICHER MENU //

AfficherMenu::AfficherMenu() : QWidget()
{
    setFixedSize(230, 120);
 
    m_boutonDialogue2 = new QPushButton("Ouvrir la boîte de dialogue", this);
    m_boutonDialogue2->move(40, 50);
 
    QObject::connect(m_boutonDialogue2, SIGNAL(clicked()), this, SLOT(ouvrirMenu()));
}
 
int AfficherMenu::ouvrirMenu() //le code pour l'action est contenu dans un paragraphe associé (ex : charger -> §199), le menu se contente de nous renvoyer au paragraphe qui nous intéresse

{
	int para=-1;
    QStringList choix;
    choix << "Sauvegarder" << "Charger" << "Revoir Texte" << "Voir Profil" << "Voir Journal" << "Inscrire Journal" << "Quitter le jeu";
    QString rep=QInputDialog::getItem(this, "Menu", "Choisissez une action : ", choix);
    if (rep == "Sauvegarder") {para=200;}
    if (rep == "Charger") {para=199;}
    if (rep == "Revoir Texte") {para=204;}
    if (rep == "Voir Profil") {para=203;}
    if (rep == "Voir Journal") {para=202;}
    if (rep == "Inscrire Journal") {para=201;}
    if (rep == "Quitter le jeu") {exit(1);}
    
    return para;
}

int AfficherMenu::ouvrirMenuDepart() 

{
	int res=-1;
    QStringList choix;
    choix << "Nouvelle Partie" << "Charger Partie" << "Quitter le jeu";
    QString rep=QInputDialog::getItem(this, "Menu", "Choisissez une action : ", choix);
    if (rep == "Nouvelle partie") {res=0;}
    if (rep == "Charger Partie") {res=1;}
    if (rep == "Quitter le jeu") {exit(1);}
    
    return res;
}

int AfficherMenu::choisiremplacement() 

{
	int partie=-1;
    QStringList choix;
    choix << "Emplacement 1" << "Emplacement 2" << "Emplacement 3";
    QString rep=QInputDialog::getItem(this, "Menu", "Choisissez un emplacement : ", choix);
    if (rep == "Emplacement 1") {partie=1;}
    if (rep == "Emplacement 2") {partie=2;}
    if (rep == "Emplacement 3") {partie=3;}
    
    return partie;
}
