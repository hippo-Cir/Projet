#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include <string>
#include <vector>

#include "Waypoint.h"
#include "Route.h"
#include "Ville.h"
#include "Contour.h"

using namespace std;

class Carte {
    private :

    public :
        int getContour()const{
            return contour;
        }
        float getEchelleLon()const{
            return echelle_lon;
        }
        std::vector<Waypoint> &getWaypoints(){
            return waypoints;
        }
        std::vector<Route> &getRoutes(){
            return routes;
        }
        std::vector<String> &getVilles(){
            return villes;
        }
        void ajoutUnWaypoint(const Waypoint& wpt){
            waypoints.push_back(wpt);
        }
        void ajoutUneRoute(const Route& rt){
            routes.push_back(rt);
        }
        void ajoutUneVille(Ville *){
            villes.push_back();
        }
        void insereUneVille(Ville *){
            villes.push_back();
        }
        void affiche() const{
            std::cout << "Carte :" << "\n";
            for ( auto &carte : carte ){
                carte.affcihe();
            }
        }
};
#endif