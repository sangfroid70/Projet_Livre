#include <iostream>
using namespace std;
#include "combat.h"
#include "classesbase.h"
#include <stdlib.h>
#include <time.h>

int lancer_de()
{ return ( (rand()%6) +1 ); }


rescombat combat (vous v,monstre m)
{
	
	if (m.get_name()!="unknown") //chaque case de la "Table des Rencontres" contient un emplacement vide réservé à un monstre ( monstre() ) mais seuls ceux qui "contiennent" un monstre lancent le combat
	 {v.affiche_vous();
	 m. affiche_monstre();
	 cout<<endl;}
	
	while (v.get_pv()>0 && m.get_pv()>0) //le combat se poursuit tant qu'un des deux combattants au moins n'est pas mort
	{ 
		int lance=0;
		int usepotion=0;
		int nbpotion=0;
		cout<<"Lancez le dé avec 1 :"<<endl;
		cin>>lance;
		
		if (lance==1)
		{ int dv1=lancer_de(); cout<<" Votre lancer :"<<dv1<<endl;
		  int dm1=lancer_de(); cout<<" Son lancer :"<<dm1<<endl;
		
		  int dv2=dv1+(v.get_armeequip()).get_degats(); 
		  if (dv2<0) {dv2=0;}
		  cout<<" Votre FORCE:"<<dv2<<endl;
		  int dm2=dm1+(m.get_armeequip()).get_degats();
		  if (dm2<0) {dm2=0;}
		  cout<<" Sa FORCE :"<<dm2<<endl;
		
		  v.changer_pv(v.get_pv()-dm2); 
		  if (v.get_pv()<0) {v.changer_pv(0);}
		  cout<<" Vos pv :"<<v.get_pv()<<endl;

		  m.changer_pv(m.get_pv()-dv2);
		  if (m.get_pv()<0) {m.changer_pv(0);}
		  cout<<" Ses pv :"<<m.get_pv()<<endl;
		  
		  
		  
		  for (int i=0;i<10;i++)
		   {if ((v.get_tab(i)).get_nom_objet() == "Potion") {nbpotion++;} } //la gestion des Potions (utilisable après chaque "round")
		  if (nbpotion>0)
			{
			 cout<<"Utiliser une potion ?"<<endl;
		     cout<<"Si oui, faites 1"<<endl;
		     cin>>usepotion;}
		  if (usepotion==1) {nbpotion--;v.changer_pv(v.get_pv()+20);v.erase_tab("Potion");}
		  
	
		}
		
		cout<<endl;
			
	}
	
	rescombat r;
	r.respv=v.get_pv();
	r.dead=-1;
	
	if (v.get_pv()<=0) {cout<<"VOUS êtes mort !"<<endl;r.dead=0;} //on vérifie qui est mort et renvoie l'information dans le main par r.dead, ce qui permet de gérer en conséquence (exit(1) si vous êtes mort, ajout d'une Potion si vous avez tué le monstre)
	else {	
		    if (m.get_name()!="unknown") 
				{cout<<"VOUS avez tué le monstre ! (et vous gagnez une Potion...)"<<endl;cout<<m.get_para_suiv()<<endl;r.dead=1;}   
		  }
			
return r;
			
}




vous transcrire_sauvegarde_perso(int ppv, string aarme, int ddegats) //récupère les informations obtenues grâce à la lecture d'un fichier de sauvegarde et remplit une nouvelle "Feuille de Personnage" identique à l'ancienne partie
{
	
	arme a=arme();
	a.changer_arme(aarme,ddegats);
	
	vous v=vous();
	v.changer_pv(ppv);
	v.changer_arme_equipee(a);
	
	return v; }
	

	 
