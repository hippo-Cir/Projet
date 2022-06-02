//                              Mini projet
//                          ALexandre Le Philippe
//                            Hippolyte Requet
//
//                                  Cir2
#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H
#include <QGroupBox>
#include <QLayout>
#include <QGraphicsView>
#include <QLabel>
#include <QMainWindow>
#include <QStatusBar>
#include <QString>
#include <QPushButton>
#include <QLineEdit>
#include <QWizard>
#include <QtGui>
#include <QApplication>
#include "model/Carte.h"
#include "SceneCarte.h"
#include "GrandeVue.h"
#include "MiniVue.h"

// Déclaration de la classe SceneCarte qui hérite de QMainWindow

class FenetrePrincipale : public QMainWindow {
	Q_OBJECT
	public:
		FenetrePrincipale(Carte &carte);
		~FenetrePrincipale();
	private:
		QGroupBox * creerGroupBoxInfos();

	private slots:
		void affiche_pos_scene( QPointF p);

	private:
		QWidget * widget_general;
		SceneCarte *myscene;
		GrandeVue *myview1;
		MiniVue *myview2;
		QStatusBar *barre_statut;

		Carte &carte;
		int hauteur;
		int largeur;

};

// Déclaration de la classe MyWizard qui hérite de QWizard

class MyWizard : public QWizard
{
    Q_OBJECT

public:
    MyWizard(QWidget *parent = 0);

public slots:
    void onAccepted();
};

// Déclaration de la classe Mypage qui hérite de QWizardPage

class MyPage : public QWizardPage
{
    Q_OBJECT
public:
    MyPage(QWidget *parent = 0);
};


#endif
