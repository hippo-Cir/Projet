//                              Mini projet
//                          ALexandre Le Philippe
//                            Hippolyte Requet
//
//                                  Cir2
#include "Pathfinding.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//Matrice adjacente
Pathfinding::Pathfinding(Carte &carte)
{
	//declaration des vectors
	std::vector<Route> routes;
	std::vector<Waypoint*> waypoints=carte.getWaypoints();
	//on récupere la taille de waypoint
	int max=waypoints.size();
	//matrice 2D de la taille de waypoint.
	std::vector<std::vector<int>> matrix(max,std::vector<int>(max));
	//on initialise la matrice à 0
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			matrix[i][j]=0;
		}
	}
	//on definie id du debut et fin de route
	int i_deb;
	int i_fin;
	//on remplace 0 par 1 quand il y a des voisins des villes grace à route
	for (int k = 0; k < max; k++) {
		i_deb=routes[k].getIDeb();
		i_fin=routes[k].getIFin();
		matrix[i_deb][i_fin]=1;
		matrix[i_fin][i_deb]=1;
	}

}

//destructeur
Pathfinding::~Pathfinding()
{

}
