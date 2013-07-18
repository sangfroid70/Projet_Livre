#include "personnage.h"
#include <iostream>
#include <sstream>
#include <QLayout>
#include <QLabel>
#include <QHBoxLayout>

#include "ecran.h"

Ecran::Ecran(Personnage const& perso , QWidget *parent) :
    QWidget(parent)
{
    QLabel *label = new QLabel (parent);

    QHBoxLayout *layout = new QHBoxLayout (this);
    layout->addWidget(label);

    std::ostringstream texte;
    texte << perso;
    label->setText(QString::fromStdString(texte.str()));
}
