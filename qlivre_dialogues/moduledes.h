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
    int m_nbDes;                // nombre de d�s
    int m_numeroDe;             // Num�ro du d� � jouer
    int m_total;                // Total des d�s
    QString m_texteBouton;      // Texte � afficher dans le bouton

    QPushButton *boutonLancer;  // Bouton du lancement de d�
    QPushButton *boutonQuitter; // explicite ;)
    QVector<Des*> mesDes;         // Tableau de x d�s
    QVector<int> m_resultats;
};

#endif
