#ifndef MODULEDES_H
#define MODULEDES_H

#include <QDialog>
#include <QVector>

class QPushButton;
class Des;

class ModuleDes : public QDialog {
    Q_OBJECT

public:
    ModuleDes(int nbDes , QWidget *parent=0);
    ~ModuleDes();
    QVector<int> resultats() const;
    int total ();

public slots :
    void lancerDe ();


private:
    int m_nbDes;                // nombre de dés
    int m_numeroDe;             // Numéro du dé à jouer
    int m_total;                // Total des dés
    QString m_texteBouton;      // Texte à afficher dans le bouton

    QPushButton *boutonLancer;  // Bouton du lancement de dé
    QPushButton *boutonQuitter; // explicite ;)
    QVector<Des*> mesDes;         // Tableau de x dés
    QVector<int> m_resultats;
};

#endif
