#include "FenetrePrincipale.h"


FenetrePrincipale::FenetrePrincipale(Carte &carte_init) : carte(carte_init) {

	widget_general = new QWidget;
	QHBoxLayout * qbl_general = new QHBoxLayout;
	widget_general->setLayout(qbl_general);
	this->setCentralWidget(widget_general);

	largeur = 600; // qApp->desktop()->screenGeometry().width() / 2;
	hauteur = 400; // qApp->desktop()->screenGeometry().height() / 2;
	setMinimumSize(largeur,hauteur);

	this->myscene = new SceneCarte(carte);
	this->myview1 = new GrandeVue(myscene, this);

	qbl_general->addWidget(creerGroupBoxInfos());

	qbl_general->addWidget(myview1);
	barre_statut = statusBar();

	connect( myview1, &GrandeVue::coord_viewport, myview2, &MiniVue::trace_viewport);
	connect( myview1, &GrandeVue::position, this, &FenetrePrincipale::affiche_pos_scene);


}

FenetrePrincipale::~FenetrePrincipale() {
}

QGroupBox * FenetrePrincipale::creerGroupBoxInfos() {
	QGroupBox * gb = new QGroupBox(tr("Infos carte"));
	gb->setMaximumWidth(largeur/3);
	QString str_tmp;

	QVBoxLayout *vbox = new QVBoxLayout;
	gb->setLayout(vbox);

	QLabel *ville_dep = new QLabel(tr("Ville de départ"));
	QLineEdit *depEdit = new QLineEdit;
	ville_dep->setBuddy(depEdit);

	QLabel *ville_arr = new QLabel(tr("Ville d'arrivée"));
	QLineEdit *arrEdit = new QLineEdit;
	ville_arr->setBuddy(arrEdit);

	QLabel *Distance = new QLabel("Distance :");
	QLineEdit *text= new QLineEdit();
	QLineEdit *text2= new QLineEdit();
	myview2 = new MiniVue(myscene, this);
	//QPushButton *bouton1=new QPushButton("Calculer");

	vbox->addWidget(ville_dep);
	vbox->addWidget(text);
	vbox->addWidget(ville_arr);
	vbox->addWidget(text2);
	//vbox->addWidget(bouton1);
	vbox->addWidget(Distance);
	vbox->addWidget(myview2);



	return gb;
}

void FenetrePrincipale::affiche_pos_scene( QPointF p){
	QString msg = "Coordonnées géographiques ("
			+ QString::number(p.x(),'f',2) + ","
			+ QString::number(p.y(),'f',2) + ")";
	barre_statut->showMessage(msg);
}


MyPage::MyPage(QWidget *parent)
        : QWizardPage(parent)
{
    // Creation et affichage des wigets sur la page
    QLabel *nomLabel = new QLabel("Nom");
    QLineEdit *nomEdit = new QLineEdit;
    nomLabel->setBuddy(nomEdit);

    QLabel *prenomLabel = new QLabel("Prenom");
    QLineEdit *prenomEdit = new QLineEdit;
    prenomLabel->setBuddy(prenomEdit);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(nomLabel, 0, 0);
    layout->addWidget(nomEdit, 0, 1);
    layout->addWidget(prenomLabel, 1, 0);
    layout->addWidget(prenomEdit, 1, 1);
    setLayout(layout);

    registerField("Nom*", nomEdit);
    registerField("Prenom*", prenomEdit);
}

MyWizard::MyWizard( QWidget *parent)
        : QWizard(parent)
{
    addPage( new MyPage );

    connect(this, SIGNAL(accepted()), this, SLOT(onAccepted()));
}

void MyWizard::onAccepted()
{
    cout << "signal/slot" << endl;
		std::string dep=field("Nom").toString().toStdString();
    // Tu peux récupérer les champs de n'importe quelle page grâce à la fonction field
    // qui renvoie un QVariant, ici converti en std::string.
    cout << "Nom : " << dep << endl;
    cout << "Prenom : " << field("Prenom").toString().toStdString() << endl;
    cout << endl;
}
