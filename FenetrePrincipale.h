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
#endif
