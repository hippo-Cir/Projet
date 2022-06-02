//
//
//                              Mini projet
//                          ALexandre Le Philippe
//                            Hippolyte Requet
//
//                                  Cir2

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

    try{
        BDD bdd("tcp://localhost:3306", "carte", "isen", "isen");
        contour = carte.getContour();
        carte.getWaypoints();
        carte.getRoutes();
        bdd.ajoutPoints(contour);
        bdd.selectWaypoint(carte);
        bdd.selectRoutes(carte);
        for (auto &route :carte.getRoutes()){
          route.affiche();
        }
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
