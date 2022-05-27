#ifndef CONTOUR_H
#define CONTOUR_H
#include <iostream>
#include <string>
#include <vector>

#include "Point.h"

using namespace std;

class Contour {
    private:
      std::vector<Point> points;
    public:
        std::vector<Point> &getPoints(){
            return points;
        }
        void ajoutUnPoint(const Point& pt){
          points.push_back(pt);
        }
};
#endif
