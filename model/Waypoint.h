//                              Mini projet
//                          ALexandre Le Philippe
//                            Hippolyte Requet
//
//                                  Cir2
#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Déclaration de la classe Waypoint

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
        }
};
#endif
