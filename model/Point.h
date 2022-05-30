#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Point{
    private :
        int num;
        float lon;
        float lat;
    public :
        Point (int num=0, float lon=0, float lat=0): num(num), lon(lon), lat(lat){
        }
        int getNum()const {
          return num;
        }
        float getLon()const {
            return lon;
        }
        float getLat()const {
            return lat;
        }
        void affiche() const{
            std::cout << "num :" << num << "lon :" << lon << "lat :" << lat << std::endl;
        }

};
#endif
