#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Récup le formulaire de Qt Designer

    // Initialiser les étiquettes de gauche avec les caractéristiques du héros et une image
    // Cette partie est juste là pour afficher quelque chose pour le moment. il faudra aller chercher les infos dynamiquement

    Personnage heros("Luc");
    std::ostringstream profilHeros;
    profilHeros << heros;
    ui->labelHeros->setText(QString::fromStdString(profilHeros.str()));

    ui->labelImage->setMaximumHeight(200);
    ui->labelImage->setMaximumWidth(200);
    ui->labelImage->setPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/img/corbeauxbleu_mini.jpg"));

    ///////////////////////////////////////////////////////////////////////////////////////////////////////

    // Initialisation des boutons, des zones texte, etc.
    QString enteteHtml ("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\"><html><head><meta name=\"qrichtext\" content=\"1\" /><link rel=\"stylesheet\" type=\"text/css\" media=\"screen\" href=\"texte/texte.css\" /></head><body>");
    enteteHtml += Fichier::charger("texte.html");
    enteteHtml += "</body></html>";
    ui->zoneTexte->setText(enteteHtml);

    ui->boutonObjet->setText("Objet");
    ui->boutonCompetence->setText("Compétences");
    ui->boutonJournal->setText("Journal");
    ui->boutonProfil->setText("Profil");
    ui->boutonAttaquer->setText("Attaquer");


    // Gestion des clicks de bouton et autres évènements
    QObject::connect(ui->boutonObjet , SIGNAL (clicked()) , this , SLOT (tester()));
    QObject::connect(ui->boutonCompetence , SIGNAL (clicked()) , this , SLOT (tester()));
    QObject::connect(ui->boutonJournal , SIGNAL (clicked()) , this , SLOT (tester()));
    QObject::connect(ui->boutonProfil , SIGNAL (clicked()) , this , SLOT (tester()));
    QObject::connect(ui->boutonAttaquer , SIGNAL (clicked()) , this , SLOT (lancerDes()));

    QObject::connect(ui->actionQuitter , SIGNAL (triggered()) , qApp , SLOT (quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tester () {
    qDebug ("Test");
}


// Voic un jet de dés
void MainWindow::lancerDes (int nombreDeDes) {
    ModuleDes monDe (nombreDeDes , this);
    QObject::connect(&monDe , SIGNAL (resultats(QVector<int>)) , this , SLOT (afficherResultat(QVector<int>)));
    monDe.exec();
}

/*void MainWindow::afficherResultat (QVector<int> const jets) const {
    for (int i =0 ; i < jets.size() ; i++) {
        //zoneTexte->setHtml(QString::number(jets[i]));
        zoneTexte->setText("<html><body><h1 style=\"color:blue;background-color :red ;\">Salut les coupains !!</h1><p>" + QString::number(jets[i]) + "</p></body></html>");
    }
}
*/
