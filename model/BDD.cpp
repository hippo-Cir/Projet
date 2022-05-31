#include "BDD.h"

BDD::BDD ( std::string host, std::string nomBDD, std::string login, std::string pwd){
		/* Create a connection */
		sql::Driver *driver = get_driver_instance();
		con = driver->connect(host, login, pwd);

		/* Connect to the MySQL database */
		con->setSchema(nomBDD);

		setlocale(LC_ALL,"C");
}
BDD::~BDD(){
	std::cout << "Fermeture connection\n";
	delete con;
}

// Waypoint BDD::selectWaypoint(){
//
// 	sql::Statement *stmt = con->createStatement();
// 	sql::ResultSet *res = stmt->executeQuery(
// 					"select * from waypoint" );
// 	res->next();
// 	Waypoint *waypoint( res->getString(1), res->getDouble(2),res->getDouble(3) );
// 	carte.ajoutUnWaypoints(waypoint);
//
// 	delete res;
// 	delete stmt;
//
// 	return waypoint;
// }
 	void BDD::selectWaypoint(Carte &carte){
	sql::Statement *stmt = con->createStatement();
	sql::ResultSet *res = stmt->executeQuery(
				"select * from waypoint");
	while (res->next()) {
		Waypoint *waypoint= new Waypoint(res->getString(1),res->getDouble(2),res->getDouble(3));
		carte.ajoutUnWaypoint(waypoint);
	}
	delete res;
	delete stmt;
}

// void BDD::insereCarte(Carte &carte){
//
// 	sql::Statement *stmt = con->createStatement();
// 	// Ajoute une nouvelle carte
// 	stmt->execute("INSERT INTO carte VALUES ('"
// 			+carte.getContour()+","
// 			+std::to_string(carte.getEchellelon())+")"
// 			);
// 	for ( auto &contour : carte.getContours() ){
// 		// Ajout mur
// 		// récup id_plan
// 		sql::ResultSet *res = stmt->executeQuery("select last_insert_id()");
// 		res->next();
// 		int id = res->getInt(1);
// 		delete res;
//
// 		// Ajout point
// 		for ( auto &pt : contour.getPoints() ){
// 		stmt->execute("INSERT INTO point VALUES ("
// 				+std::to_string(pt.getNum())+","
// 				+std::to_string(pt.getLat())+","
// 				+std::to_string(pt.getLon())+")"
// 				);
// 		} // fin insert point
//
// 	} // fin insert mur
//
// 	delete stmt;
// }
//
// void BDD::ajoutContours(Carte &carte){
//
// 	sql::Statement *stmt = con->createStatement();
// 	sql::ResultSet *res = stmt->executeQuery(
// 				"select * from contour");
// 	while (res->next()) {
// 		Point pt(res->getInt(1),res->getDouble(2),res->getDouble(3) );
// 		contour.ajoutUnPoint(pt);
// 	}
// 	delete res;
// 	delete stmt;
// }
//
// void BDD::ajoutWaypoints(Carte &carte){
//
// 	sql::Statement *stmt = con->createStatement();
// 	sql::ResultSet *res = stmt->executeQuery(
// 				"select * from waypoint");
// 	while (res->next()) {
// 		Waypoint wpt(res->getString(1),res->getDouble(2),res->getDouble(3));
// 		waypoints.ajoutUnWaypoint(wpt);
// 	}
// 	delete res;
// 	delete stmt;
// }
//
// void BDD::ajoutVilles(Carte &carte){
//
// 	sql::Statement *stmt = con->createStatement();
// 	sql::ResultSet *res = stmt->executeQuery(
// 				"select * from ville where nom=");
// 	while (res->next()) {
// 		carte.ajoutUneVille(Ville(res->getString(1),res->getString(2),res->getInt(3),res->getString(4) );
// 	}
// 	delete res;
// 	delete stmt;
// }
//
//
// void BDD::ajoutRoutes(Carte &carte){
//
// 	sql::Statement *stmt = con->createStatement();
// 	sql::ResultSet *res = stmt->executeQuery(
// 				"select * from route where nom_debut=");
// 	while (res->next()) {
// 		Route rou(res->getString(1),res->getString(2),res->getInt(3) );
// 	}
// 	delete res;
// 	delete stmt;
// }

void BDD::ajoutPoints(Contour &contour){
	sql::Statement *stmt = con->createStatement();
	sql::ResultSet *res = stmt->executeQuery(
		"SELECT * FROM contour");
	while(res->next()){
		Point pt(res->getInt(1),res->getDouble(2),res->getDouble(3));
		contour.ajoutUnPoint(pt);
	}
}
//
// void BDD::ajoutWaypoints(std::vector<Waypoint> &waypoints){
// 	sql::Statement *stmt = con->createStatement();
// 	sql::ResultSet *res = stmt->executeQuery(
// 		"SELECT * from waypoint");
// 	while(res->next()){
// 		Waypoint wpt(res->getString(1),res->getDouble(2),res->getDouble(3));
// 		carte.ajoutUnWaypoint(wpt);
// 	}
// }

void BDD::ajoutRoutes(Carte& carte){
	sql::Statement *stmt = con->createStatement();
	sql::ResultSet *res = stmt->executeQuery(
		"SELECT * from route");
	while(res->next()){
		Route rt(res->getInt(1),res->getInt(2),res->getInt(3));
		carte.ajoutUneRoute(rt);
	}
}

// void BDD::ajoutVilles(std::vector<Ville> &villes){
// 	sql::Statement *stmt = con->createStatement();
// 	sql::ResultSet *res = stmt->executeQuery(
// 		"SELECT * from ville");
// 	while(res->next()){
// 		Ville vl(res->getString(1),res->getInt(2),res->getString(3));
// 		carte.insereUneVille(vl);
// 	}
// }
