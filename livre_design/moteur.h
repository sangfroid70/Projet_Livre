#ifndef MOTEUR_H
#define MOTEUR_H

#include <QObject>

class Moteur : public QObject
{
    Q_OBJECT
public:
    explicit Moteur(QObject *parent = 0);
    ~Moteur ();

signals:

public slots:

};

#endif // MOTEUR_H
