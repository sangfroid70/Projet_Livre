#ifndef ECRAN_H
#define ECRAN_H

#include <QWidget>

class Personnage;

class Ecran : public QWidget
{
    Q_OBJECT
public:
    explicit Ecran(Personnage const& perso , QWidget *parent = 0);


};

#endif // ECRAN_H
