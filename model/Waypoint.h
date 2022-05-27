#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Waypoint {
    private :
        std::string nom;
        float lon;
        float lat;
        std::string infos;
    public :
        Waypoint (std::string nom="", float lon=0, float lat=0): nom(nom),lat(lat),lon(lon){
        }
        std::string getNom() const{
            return nom;
        }
        float getLon() const{
            return lon;
        }
        float getLat()const{
            return lat;
        }
        virtual bool isVille()const{
            return false;
        }
        std::string getInfos()const{
            return infos;
        }
        void affiche() const{
            std::cout << "Waypoint" << nom << "longitude" << lon << "latitude" << lat << "\n";
          //  for ( auto &waypoint : waypoints ){
          //      waypoint.affiche();
          //  }
        }
};
#endif
