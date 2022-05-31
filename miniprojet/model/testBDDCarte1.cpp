#include <iostream>
#include <vector>
#include <cppconn/exception.h>

#include "BDD.h"
#include "Carte.h"
#include "Point.h"
#include "Ville.h"
#include "Waypoint.h"
#include "Route.h"
#include "Contour.h"

int main(void){
    std::cout << "Lecture de carte" << std::endl;
    Carte carte;
    Contour contour;
    Route route;
    std::vector<Waypoint *> waypoint;

    try{
        BDD bdd("tcp://localhost:3306", "carte", "isen", "isen");
        contour = carte.getContour();
        carte.getWaypoints();
        bdd.ajoutPoints(contour);
        bdd.selectWaypoint(carte);
      //  carte.affiche();
      //  contour.affiche();
        // route = carte.getRoutes();
        // bdd.ajoutRoutes(carte);
        // route.affiche();
        //carte = bdd.selectCarte(1);
        // bdd.ajoutRoutes(carte);
        // bdd.ajoutVilles(carte);
        // bdd.ajoutWaypoints(carte);
        // bdd.ajoutPointsContours(contour);
    }
    catch (sql::SQLException &e) {
  		std::cout << "# ERR: " << e.what();
  		std::cout << " (MySQL error code: " << e.getErrorCode();
  		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
  	}
  	catch(...){
  		std::cout << "Exception non trapp�e"<<std::endl;
  	}

  	return EXIT_SUCCESS;
  }
