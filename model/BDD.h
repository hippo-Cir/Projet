#ifndef BDD_H
#define BDD_H

#include <iostream>
#include <string>
#include <vector>
#include <clocale>

#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "Carte.h"
#include "Contour.h"
#include "Point.h"
#include "Route.h"
#include "Ville.h"
#include "Waypoint.h"

class BDD {
	private :
		Carte carte;
		sql::Connection *con;
		sql::Statement *stmt_route;
		sql::ResultSet *res_route;
		sql::Statement *stmt_waypoint;
		sql::ResultSet *res_waypoint;
		sql::Statement *stmt_point;
		sql::ResultSet *res_point;

	public :
		BDD ( std::string host, std::string nomBDD, std::string login, std::string pwd);
		BDD (){}
		~BDD();
		void ajoutPoints(Contour &contour);
		void ajoutVilles(std::vector<Ville> &villes);
		void selectWaypoint(Carte &carte);
		void selectRoutes(Carte &carte);

};
#endif
