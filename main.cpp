// includes VIEW
#include <QApplication>
#include <QMessageBox>
#include <QtGui>
#include <QWizard>
#include "LoginDialog.h"
#include "FenetrePrincipale.h"

// includes MODEL
#include <cppconn/exception.h>
#include "model/Carte.h"
#include "model/BDD.h"

int main(int argc, char **argv) {

	QApplication app(argc, argv);

	LoginDialog dlg;
	std::string host, base, user, pwd;

	if ( ! dlg.exec() ){ // Ouverture de la boite de dialogue
		std::cout << "Sortie de l'application\n";
		return 1;
	}
	// R�cup�ration des saisies apr�s fermeture de la Dialog box
	dlg.getResult(host, base, user, pwd);

	std::cout << "Lecture base carte" << std::endl;
	Carte carte;
	Contour contour;
	std::vector<Waypoint *> waypoints;
	std::vector<Route> routes;
	try {
		// Connexion BD
		BDD bdd("tcp://"+host+":3306", base, user, pwd);
		// R�cup�ration du plan
		bdd.ajoutPoints(contour);
		carte.setContour(contour);
		bdd.selectWaypoint(carte);
		carte.getRoutes();
		bdd.selectRoutes(carte);
	}
	//Traitement des erreurs de connection
	catch (sql::SQLException &e) {
		std::cout << "Erreur MySQL. Sortie de l'application\n";
		QMessageBox msg( QMessageBox::Critical, "Erreur mySQL", e.what());
		msg.exec();
		return 1;
	}
	//affichage de la fenetre principale apres la connection
	FenetrePrincipale mw (carte);
	mw.show();
	QWizard *wizard = new MyWizard();
	wizard->show();
	return app.exec();

}
