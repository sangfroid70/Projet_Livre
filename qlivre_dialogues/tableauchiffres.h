#ifndef TABLEAUCHIFFRES_H
#define TABLEAUCHIFFRES_H

#include <QLineEdit>
#include <QVector>

#include <QHBoxLayout>
#include <QLCDNumber>

class TableauChiffres : public QLineEdit
{
    Q_OBJECT
public:
    explicit TableauChiffres(int taille , QWidget *parent = 0);
    explicit TableauChiffres(QVector<int> const& tableau , QWidget *parent = 0);
    enum Affichage {Tout , Total , Chiffres , Defaut};
    void setChiffres(QVector<int> const& tableau);
    int total();
    void effacer ();
    void afficher (Affichage affichage = TableauChiffres::Defaut);
    void setAffichage (Affichage affichage);

signals:

public slots:

private:
    QVector<int> m_chiffres;
    QLineEdit *ecranLineEdit;
    int m_taille;
    QString m_texte;
    Affichage m_affichage;

    void totalLabel ();
    void toutLabel ();
    void chiffresLabel ();

};

#endif // TableauChiffres_H
