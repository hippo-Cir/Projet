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

    public :
        Route (int deb=0, int fin=0, int distance=0): i_deb(deb), i_fin(fin), distance(distance){
        }
        int getIDeb()const{
            return ideb;
        }
        int getIFin()const{
            return ifin;
        }
        int getDistance()const{
            return distance;
        }
        std::string getInfos()const {
            return infos;
        }
        void affiche() const{
            std::cout << "Départ :" << i_deb << "Fin :" << i_fin << "Distance :" << distance << "\n";
            for ( auto &route : route ){
                route.affcihe();
            }
        }
};
#endif