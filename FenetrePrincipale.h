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

class FenetrePrincipale : public QMainWindow {
	Q_OBJECT
	public:
		FenetrePrincipale(Carte &carte);
		~FenetrePrincipale();
	private:
		QGroupBox * creerGroupBoxInfos();

	private slots:
		void affiche_pos_scene( QPointF p);
	//	void onAccepted();

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

class MyWizard : public QWizard
{
    Q_OBJECT

public:
    MyWizard(QWidget *parent = 0);

    // Cette méthode virtuelle est appelée
    // lorsque la boite de dialogue/wizard est
    // validée
    //void accept();

public slots:
    void onAccepted();
};

class MyPage : public QWizardPage
{
    Q_OBJECT
public:
    MyPage(QWidget *parent = 0);
};


#endif
