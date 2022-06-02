//                              Mini projet
//                          ALexandre Le Philippe
//                            Hippolyte Requet
//
//                                  Cir2
#ifndef VILLE_H
#define VILLE_H
#include <iostream>
#include <string>
#include <vector>

#include "Waypoint.h"

using namespace std;

// Déclaration de la classe Ville qui hérite de Waypoint

class Ville : public Waypoint {
    private :
       std::string code_postal;
       int nb_habitants;
       std::string site;
       std::string infos;
       std::vector<Ville> villes;
    public :
        Ville (std::string cp="", int nbh=0, std::string site=""): code_postal(cp), nb_habitants(nbh), site(site){
        }
        std::string getSite() const{
            return site;
        }
        virtual bool isVille()const{
            return true;
        }
        std::string getInfos() const{
            return infos;
        }
        void affiche() const{
            std::cout << "Ville code postal :" << code_postal << "(" << nb_habitants << ")"<< site << "\n";
            for ( auto &ville : villes ){
                ville.affiche();
            }
        }
};
#endif
