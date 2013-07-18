#include "des.h"

Des::Des(uint numDigits , QWidget *parent) :
    QLCDNumber(numDigits , parent)
{
    setSegmentStyle(QLCDNumber::Flat);
    setDigitCount(1);

    timer = new QTimer (this);
    timer->setInterval (10);
    timer->start();
    QObject::connect (timer , SIGNAL (timeout() ) , this , SLOT (refresh()));
}

Des::~Des () {

}

void Des::stopper () {
    timer->stop ();
}

void Des::refresh () {
    display((qrand()%6)+1);     // chaque dixième de seconde, un nouveau chiffre aléatoire est généré
}
