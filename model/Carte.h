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
      Contour contour;
      float echelle_lon;
      std::vector<Waypoint *> waypoints;
      std::vector<Route> routes;
      std::vector<string> nomVilles;
      Ville *villes;
    public :

        Contour getContour(){
            return contour;
        }
        float getEchelleLon()const{
            return echelle_lon;
        }
        std::vector<string> getNomsVilles(){
            return nomVilles;
        }
        std::vector<Waypoint *> getWaypoints(){
            return waypoints;
        }
        void ajoutUnWaypoint(Waypoint *waypoint){
          waypoints.push_back(waypoint);
        }
        std::vector<Route> &getRoutes(){
            return routes;
        }
        // std::vector<Ville> &getVilles(){
        //     return villes;
        // }
        void setContour(Contour contours){
            this->contour=contours;
        }
        // void ajoutUnWaypoint(Waypoint* wpt){
        //     waypoints.push_back(wpt);
        // }
        void ajoutUneRoute(const Route& rt){
            routes.push_back(rt);
        }
        // void insereUneVille(Ville* vl){
        //     villes.push_back(vl);
        // }
        void affiche() const{
            std::cout << "Carte :" <<"\n";
            // //  for ( auto &contour : contour ){
            // //      contour.affcihe();
            // //  }
        }
};
#endif
