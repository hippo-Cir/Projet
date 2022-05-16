#include "FenetrePrincipale.h"


FenetrePrincipale::FenetrePrincipale(Plan &plan_init) : plan(plan_init) {

	widget_general = new QWidget;
	QHBoxLayout * qbl_general = new QHBoxLayout;
	widget_general->setLayout(qbl_general);
	this->setCentralWidget(widget_general);

	largeur = 600; // qApp->desktop()->screenGeometry().width() / 2;
	hauteur = 400; // qApp->desktop()->screenGeometry().height() / 2;
	setMinimumSize(largeur,hauteur);

	myscene = new ScenePlan(plan);
	myview1 = new GrandeVue(myscene, this, plan.getOrientation());

	qbl_general->addWidget(creerGroupBoxInfos());

	qbl_general->addWidget(myview1);
	barre_statut = statusBar();

	connect( myview1, &GrandeVue::coord_viewport, myview2, &MiniVue::trace_viewport);
	connect( myview1, &GrandeVue::position, this, &FenetrePrincipale::affiche_pos_scene);


}

FenetrePrincipale::~FenetrePrincipale() {
}

QGroupBox * FenetrePrincipale::creerGroupBoxInfos() {
	QGroupBox * gb = new QGroupBox(tr("Infos plan"));
	gb->setMaximumWidth(largeur/3);
	QString str_tmp;

	QVBoxLayout *vbox = new QVBoxLayout;
	gb->setLayout(vbox);

	QTextEdit *text= new QTextEdit();
	myview2 = new MiniVue(myscene, this);
	QPushButton *bouton1=new QPushButton("Calculer");

	vbox->addWidget(text);
	vbox->addWidget(bouton1);
	vbox->addWidget(myview2);

	return gb;
}

void FenetrePrincipale::affiche_pos_scene( QPointF p){
	QString msg = "Coordonnées scène ("
			+ QString::number(p.x(),'f',2) + ","
			+ QString::number(p.y(),'f',2) + ")";
	barre_statut->showMessage(msg);
}
