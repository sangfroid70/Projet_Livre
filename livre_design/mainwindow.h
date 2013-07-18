#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QPixmap>
#include "personnage.h"
#include "moduledes.h"
#include <iostream>
#include <sstream>
#include <QTextStream>
#include <QFile>
#include "fichier.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void tester ();
    void lancerDes (int nombreDeDes = 1);
    //void afficherResultat (QVector<int> const jets) const;

private:
    Ui::MainWindow *ui;
    QString charger (const QString &nomFichier);


};

#endif // MAINWINDOW_H
