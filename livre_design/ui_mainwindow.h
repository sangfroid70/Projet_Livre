/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Feb 20 16:45:51 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QTextEdit>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRegles_du_jeu;
    QAction *actionNouvelle_partie;
    QAction *actionCharger_Partie;
    QAction *actionEnregistrer_partie;
    QAction *actionQuitter;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelHeros;
    QLabel *labelImage;
    QTextEdit *zoneTexte;
    QVBoxLayout *verticalLayout_4;
    QPushButton *boutonObjet;
    QPushButton *boutonCompetence;
    QPushButton *boutonJournal;
    QPushButton *boutonProfil;
    QPushButton *boutonAttaquer;
    QMenuBar *menuBar;
    QMenu *menuLivre_d_aventure;
    QMenu *menuAide;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(834, 569);
        actionRegles_du_jeu = new QAction(MainWindow);
        actionRegles_du_jeu->setObjectName(QString::fromUtf8("actionRegles_du_jeu"));
        actionNouvelle_partie = new QAction(MainWindow);
        actionNouvelle_partie->setObjectName(QString::fromUtf8("actionNouvelle_partie"));
        actionCharger_Partie = new QAction(MainWindow);
        actionCharger_Partie->setObjectName(QString::fromUtf8("actionCharger_Partie"));
        actionEnregistrer_partie = new QAction(MainWindow);
        actionEnregistrer_partie->setObjectName(QString::fromUtf8("actionEnregistrer_partie"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setFlat(false);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelHeros = new QLabel(groupBox);
        labelHeros->setObjectName(QString::fromUtf8("labelHeros"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelHeros->sizePolicy().hasHeightForWidth());
        labelHeros->setSizePolicy(sizePolicy);
        labelHeros->setFrameShape(QFrame::StyledPanel);
        labelHeros->setFrameShadow(QFrame::Raised);
        labelHeros->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(labelHeros);

        labelImage = new QLabel(groupBox);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));

        verticalLayout->addWidget(labelImage);


        horizontalLayout_2->addLayout(verticalLayout);

        zoneTexte = new QTextEdit(groupBox);
        zoneTexte->setObjectName(QString::fromUtf8("zoneTexte"));

        horizontalLayout_2->addWidget(zoneTexte);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        boutonObjet = new QPushButton(groupBox);
        boutonObjet->setObjectName(QString::fromUtf8("boutonObjet"));

        verticalLayout_4->addWidget(boutonObjet);

        boutonCompetence = new QPushButton(groupBox);
        boutonCompetence->setObjectName(QString::fromUtf8("boutonCompetence"));

        verticalLayout_4->addWidget(boutonCompetence);

        boutonJournal = new QPushButton(groupBox);
        boutonJournal->setObjectName(QString::fromUtf8("boutonJournal"));

        verticalLayout_4->addWidget(boutonJournal);

        boutonProfil = new QPushButton(groupBox);
        boutonProfil->setObjectName(QString::fromUtf8("boutonProfil"));

        verticalLayout_4->addWidget(boutonProfil);

        boutonAttaquer = new QPushButton(groupBox);
        boutonAttaquer->setObjectName(QString::fromUtf8("boutonAttaquer"));

        verticalLayout_4->addWidget(boutonAttaquer);


        horizontalLayout_2->addLayout(verticalLayout_4);


        horizontalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 834, 25));
        menuLivre_d_aventure = new QMenu(menuBar);
        menuLivre_d_aventure->setObjectName(QString::fromUtf8("menuLivre_d_aventure"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuLivre_d_aventure->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuLivre_d_aventure->addAction(actionNouvelle_partie);
        menuLivre_d_aventure->addAction(actionCharger_Partie);
        menuLivre_d_aventure->addAction(actionEnregistrer_partie);
        menuLivre_d_aventure->addSeparator();
        menuLivre_d_aventure->addAction(actionQuitter);
        menuAide->addAction(actionRegles_du_jeu);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionRegles_du_jeu->setText(QApplication::translate("MainWindow", "R\303\251gles du jeu", 0, QApplication::UnicodeUTF8));
        actionNouvelle_partie->setText(QApplication::translate("MainWindow", "Nouvelle partie", 0, QApplication::UnicodeUTF8));
        actionCharger_Partie->setText(QApplication::translate("MainWindow", "Charger partie", 0, QApplication::UnicodeUTF8));
        actionEnregistrer_partie->setText(QApplication::translate("MainWindow", "Enregistrer partie", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "R\303\251cit", 0, QApplication::UnicodeUTF8));
        labelHeros->setText(QApplication::translate("MainWindow", "Caract\303\251ristiques du h\303\251ros", 0, QApplication::UnicodeUTF8));
        labelImage->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        zoneTexte->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"</body></html>", 0, QApplication::UnicodeUTF8));
        boutonObjet->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        boutonCompetence->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        boutonJournal->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        boutonProfil->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        boutonAttaquer->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        menuLivre_d_aventure->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
