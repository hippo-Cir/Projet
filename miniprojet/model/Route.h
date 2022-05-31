#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Route{
    private :
        int i_deb;
        int i_fin;
        int distance;
        std::string infos;
        std::vector<Route> routes;
    public :
        Route (int deb=0, int fin=0, int distance=0): i_deb(deb), i_fin(fin), distance(distance){
        }
        int getIDeb()const{
            return i_deb;
        }
        int getIFin()const{
            return i_fin;
        }
        int getDistance()const{
            return distance;
        }
        std::string getInfos()const {
            return infos;
        }
        void affiche() const{
            std::cout << "Départ :" << i_deb << "Fin :" << i_fin << "Distance :" << distance << "\n";
            for ( auto &route : routes ){
                route.affiche();
            }
        }
};
#endif
