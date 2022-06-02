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

void BDD::selectWaypoint(Carte &carte){
	stmt_waypoint = con->createStatement();
	res_waypoint = stmt_waypoint->executeQuery("SELECT * FROM waypoint");
	while (res_waypoint->next()) {
		Waypoint *waypoint= new Waypoint(res_waypoint->getString(1),res_waypoint->getDouble(2),res_waypoint->getDouble(3));
		carte.ajoutUnWaypoint(waypoint);
	}
}

void BDD::selectRoutes(Carte &carte){
	stmt_route = con->createStatement();
	res_route = stmt_route->executeQuery("SELECT * FROM route");
	int x, y;
	int i_deb=0, i_fin=0;
	while(res_route->next()){
		 x=0, y=0;
		stmt_waypoint = con->createStatement();
		res_waypoint = stmt_waypoint->executeQuery("SELECT * FROM waypoint");
		while(res_waypoint->next()){
			if(res_route->getString(1)==res_waypoint->getString(1) && res_route->getString(2)==res_waypoint->getString(1)){
				i_deb = x, i_fin = y;
			}
			x++, y++;
		}
		Route rt(i_deb,i_fin,res_route->getInt(3));
		carte.ajoutUneRoute(rt);
	}
}

void BDD::ajoutPoints(Contour &contour){
	stmt_point = con->createStatement();
	res_point = stmt_point->executeQuery("SELECT * FROM contour");
	while(res_point->next()){
		Point pt(res_point->getInt(1),res_point->getDouble(2),res_point->getDouble(3));
		contour.ajoutUnPoint(pt);
	}
}
