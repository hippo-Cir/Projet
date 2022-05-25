#ifndef VILLE_H
#define VILLE_H
#include <iostream>
#include <string>
#include <vector>

#include "Waypoint.h"

using namespace std;

class Ville : public Waypoints {
    private : 
       std::string code_postal;
       int nb_habitants;
       std::string site; 
    public :
        Ville (std::string cp="", int nbh=0, std::string site=""): code_postal(cp), nb_habitants(nbh), site(site){
        }
        std::string getSite() const{
            return site;
        }
        bool isVille(){
            return true;
        }
        std::string getInfos() const{
            return infos;
        }
        void affiche() const{
            std::cout << "Ville code postal :" << code_postal << "(" << nb_habitants << ")"<< site << "\n";
            for ( auto &ville : ville ){
                ville.affiche();
            }
        }
};
#endif