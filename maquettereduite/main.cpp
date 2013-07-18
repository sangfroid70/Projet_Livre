#include <QtGui>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include "classesbase.h"
#include "combat.h"
#include <time.h>


int main(int argc, char *argv[])
{

	srand(time(NULL));

    QApplication app(argc,argv);


	// OBJETS DE BASE

	// il y en a plusieurs types : les armes, les objets, les monstres...

	arme a1=arme();
	a1.changer_arme("Poteau",2);

    arme a2=arme();
	a2.changer_arme("Crocs",1);

	objet o1=objet();
	o1.changer_objet("Bride");

	monstre m1=monstre();
	m1.changer_nom("Each Uisge");
	m1.changer_descr("Il aurait dû garder ses sales pattes loin de Judith...");
	m1.changer_pv(30);
	m1.changer_para_suiv("Allez au 9");
    m1.changer_arme_equipee(a2);



	// LES TABLEAUX //

	//chaque tableau contient des emplacements vides correspondants aux constructeurs de chaque classe ; parfois, les emplacements vides sont "remplis" par des objets/monstres/paragraphes/armes

	monstre* table_rencontres=new monstre[9]; //le tableau des monstres
	for (int i=1;i<10;i++) {table_rencontres[i]=monstre();}
	table_rencontres[8]=m1;

	objet* table_item=new objet[9]; //le tableau des objets
	for (int i=1;i<10;i++) {table_item[i]=objet();}
	table_item[4]=o1;

	arme* armurerie=new arme[9]; // le tableau des armes
	for (int i=1;i<10;i++) {armurerie[i]=arme();}
	armurerie[8]=a1;

	string* paragraphe=new string[9]; // le tableau des paragraphes
	for (int i=1;i<10;i++) {paragraphe[i]="rien";}

	paragraphe[1]="un.txt";
	paragraphe[2]="deux.txt";
	paragraphe[3]="trois.txt";
	paragraphe[4]="quatre.txt";
	paragraphe[5]="cinq.txt";
	paragraphe[6]="six.txt";
	paragraphe[7]="sept.txt";
	paragraphe[8]="huit.txt";
	paragraphe[9]="neuf.txt";


	// REGLES DU JEU


	AfficherTexte* aff=new AfficherTexte();
	AfficherRegles* regl=new AfficherRegles();
	aff=regl->ouvrirDialogue();
	if (aff != NULL)
	{aff->show();
	app.exec();
	aff->close();}





	// MOTEUR DE JEU


	 vous v=vous(); //création d'une Feuille de Personnage
	 int para=1;


	//menu de départ

	 cout<<endl;
	 cout<<"	DEBUT DU JEU	"<<endl;
	 cout<<endl;


	//affichage de la Feuille de Personnage
	v.affiche_vous();


	//lancement de la boucle permettant de naviguer entre les paragraphes
	while (para <= 9)
	 {


		AfficherTexte* aff1=new AfficherTexte(); //affichage du texte du paragraohe
        aff1->affichetxt(paragraphe[para]);
        aff1->show();
        app.exec();
        aff1->close();

		rescombat resu=combat(v,table_rencontres[para]); //gestion du combat
		v.changer_pv(resu.respv);
		if (resu.dead == 1) {v.ajout_objet(p);}
		if (resu.dead == 0)
			{AfficherTexte* aff1=new AfficherTexte();
			aff1->affichetxt(paragraphe[14]);
			aff1->show();
			app.exec();
			aff1->close();
			exit(1);}

		v.ajout_objet(table_item[para]);	//gestion des objets et armes
		v.changer_arme_equipee(armurerie[para]);}


	  if (para == 4)
	  {

        paragraphe[7]="septbis.txt";

	  }



		if (para == 9) //spécial : le dernier paragraphe met fin à l'Aventure
        {AfficherTexte* aff4=new AfficherTexte();
        aff4->affichetxt(paragraphe[para]);
        aff4->show();
        app.exec();
        aff4->close();}





cout<<"	FIN DU JEU	"<<endl;
cout<<endl;



return 0;

}
