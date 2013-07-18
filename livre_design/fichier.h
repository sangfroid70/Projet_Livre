#ifndef FICHIER_H
#define FICHIER_H

#include <QObject>
#include <QApplication>
#include <QString>
#include <QTextStream>
#include <QFile>

class Fichier : public QObject
{
    Q_OBJECT
public:
    explicit Fichier(QObject *parent = 0);
    ~Fichier ();
    static QString charger (QString const &nomFichier);

signals:

public slots:

};

#endif // FICHIER_H
