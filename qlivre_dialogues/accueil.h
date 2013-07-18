#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QDialog>

class QVBoxLayout;
class QDialogButtonBox;
class Ligne;
class Personnage;

class Accueil : public QDialog
{
    Q_OBJECT
public:
    explicit Accueil(QWidget *parent = 0);
    Personnage creerPerso () const;

signals:

public slots:
    void accepter ();

private:
    int m_ligne;
    QVBoxLayout *layoutOngletNouveau;
    QVBoxLayout *layout;
    QDialogButtonBox *boutonsDialogue;

    Ligne *nom;
    Ligne *vie;
    Ligne *attaque;
    Ligne *magie;
};

#endif // ACCUEIL_H
