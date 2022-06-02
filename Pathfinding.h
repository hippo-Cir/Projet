//                              Mini projet
//                          ALexandre Le Philippe
//                            Hippolyte Requet
//
//                                  Cir2
#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "model/Route.h"
#include "model/Carte.h"
#include "model/Waypoint.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pathfinding
{
    public:
        Pathfinding(Carte &carte);
        virtual ~Pathfinding();

    private:
        std::vector<std::vector<int>> matrix;
        std::vector<Route> routes;
        std::vector<Waypoint> truc;
};

#endif
