#include "BDD.h"
#include <math.h>

#define PI 3,14

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

void BDD::selectRoutes(Carte &carte){
	sql::Statement *stmt = con->createStatement();
	sql::ResultSet *res = stmt->executeQuery(
				"select * from route");
	int a;
	int b;
	int i_deb=0;
	int i_fin=0;
	while(res->next()){
		 a=0;
		 b=0;
		sql::Statement *stmt2 = con->createStatement();
		sql::ResultSet *res2 = stmt2->executeQuery("select * from waypoint");
		while(res2->next()){
			if(res->getString(1)==res2->getString(1)){
				i_deb = a;
			}
			if(res->getString(2)==res2->getString(1)){
				i_fin = b;
			}
			a++;
			b++;
		}
		Route rt(i_deb,i_fin,res->getInt(3));
		carte.ajoutUneRoute(rt);
	}

}

void BDD::ajoutPoints(Contour &contour){
	sql::Statement *stmt = con->createStatement();
	sql::ResultSet *res = stmt->executeQuery(
		"SELECT * FROM contour");
	while(res->next()){
		Point pt(res->getInt(1),res->getDouble(2),res->getDouble(3));
		contour.ajoutUnPoint(pt);
	}
}

void BDD::ajoutRoutes(Carte& carte){
	sql::Statement *stmt = con->createStatement();
	sql::ResultSet *res = stmt->executeQuery(
		"SELECT * from route");
	while(res->next()){
		Route rt(res->getInt(1),res->getInt(2),res->getInt(3));
		carte.ajoutUneRoute(rt);
	}
}

void BDD::fonctionCos(){
	cos = cos(48° * PI/180)
}
