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
	public :
		BDD ( std::string host, std::string nomBDD, std::string login, std::string pwd);
		BDD (){}
		~BDD();

		Carte selectWaypoint(std::string nom);
		void ajoutContour(Plan &plan);
		void ajoutPoints(Mur &mur);
		Plan getPlan(int id);
		void inserePlan(Plan &plan);

	private :
		Carte carte;
		sql::Connection *con;
};
#endif
