#ifndef LIGNE_H
#define LIGNE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include "moduledes.h"
#include "tableauchiffres.h"

class QHBoxLayout;
class QLineEdit;
class QPushButton;
class QCheckBox;
class TableauChiffres;


class Ligne : public QWidget
{
    Q_OBJECT

public:
    enum Style {Texte , Nombres};
    explicit Ligne(QString titre , Style style = Ligne::Texte , int nbDes = 0 , QWidget *parent = 0);
    bool estValide ();
    QString text();
    int value ();

public slots:
    void checker ();
    void lancer();

private:
    QHBoxLayout *layout;
    QString m_titre;
    Style m_style;
    int m_nbDes;

    QLineEdit *zoneTexte;
    QPushButton *bouton;
    QCheckBox *checkBox;
    TableauChiffres *affichage;

    void intituler ();
    void creerLineEdit();
    void creerBoutonDes();
    void creerCheckBox();

};

#endif // LIGNE_H
