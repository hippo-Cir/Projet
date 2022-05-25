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
    std::vector<Mur>

    try{
        BDD bdd("tcp://localhost:3306", "carte", "isen", "isen29");
        carte = bdd.selectCarte(1);
        bdd.ajoutUneRoute(carte);
        bdd.ajoutUneVille(carte);
        bdd.ajoutUnWaypoint(carte);
        bdd.ajoutContour(carte);

        for (auto &contour : carte.getWaypoints()){
            bdd.ajoutPoints(contour);
        }
        for (auto &waypoint : carte.getWaypoints()){
            bdd.ajoutVilles(waypoint);
        }
        carte.affcihe();
    }
    catch (sql::SQLException &e){
        std::cout << "# ERR " << e.what();
        std::cout << " (Mysql error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState << " )" << std::endl;
    }
    catch(...){
        std::cout << "Exception non trappe" << std::endl;
    }
    return EXIT_SUCCESS;
}
    