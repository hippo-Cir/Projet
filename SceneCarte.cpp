//                              Mini projet
//                          ALexandre Le Philippe
//                            Hippolyte Requet
//
//                                  Cir2
#include "SceneCarte.h"

std::map<std::string, QColor> SceneCarte::tab_couleurs = {{"rouge", Qt::red},{"bleu", Qt::blue} ,{"noir", Qt::black} ,{"vert", Qt::green}};

SceneCarte::SceneCarte(Carte &carte){
	// Ajout des items graphiques dans la scène
	afficher_contours(carte);
	afficher_waypoints(carte);
	afficher_routes(carte);
}

//Fonction pour afficher tous les contours de la map

void SceneCarte::afficher_contours(Carte &carte){
	Contour contour;
	qreal epaisseur_contour = 0.02;// épaisseur contour
	contour = carte.getContour();
	QColor couleur_contour = tab_couleurs["noir"];
	QColor couleur_remplissage = tab_couleurs["vert"];
	Point *points = contour.getPoints().data();
	int nombre_points = contour.getPoints().size();

	for ( int i=0; i < nombre_points-1; ++i ){
		polygone << QPointF(points[i].getLat(),points[i].getLon());
	}
	polygone << QPointF(points[nombre_points-1].getLat(),points[0].getLon());
	QGraphicsPolygonItem* outlight = this->addPolygon(QPolygonF(polygone),
																										QPen(QColor(couleur_contour),epaisseur_contour),
																										QBrush(QColor(couleur_remplissage)));
}

//Fonction pour afficher tous les waypoints de la map

void SceneCarte::afficher_waypoints(Carte &carte){
	qreal epaisseur_waypoint = 0;
	epaisseur_waypoint = 0.04;
	QColor couleur = Qt::blue;
	waypoints = carte.getWaypoints();

	for (auto &waypoints : carte.getWaypoints()){
		//Affichage des Waypoints en cercle avec EllipseItem
		QGraphicsEllipseItem *point = new QGraphicsEllipseItem ( -epaisseur_waypoint/2, -epaisseur_waypoint/2,epaisseur_waypoint ,epaisseur_waypoint );
		point->setPos(waypoints->getLat(), waypoints->getLon());
		point->setPen(QPen(couleur,epaisseur_waypoint,Qt::SolidLine));
		point->setBrush(QBrush(couleur,Qt::SolidPattern));
		this->addItem(point);
	}
}

//Fonction pour afficher toutes les routes de la map

void SceneCarte::afficher_routes(Carte &carte){
	qreal epaisseur_routes = 0;
  QColor couleur_routes = tab_couleurs["noir"];
	routes = carte.getRoutes();
	waypoints = carte.getWaypoints();

	QGraphicsLineItem *ligne = nullptr;

	for (auto &routes : carte.getRoutes()){
		//Récupération des Id pour initialiser les routes
		int id_deb = routes.getIDeb();
		int id_fin = routes.getIFin();
		//Affichage des routes avec QGraphicsLineItem
		ligne = new QGraphicsLineItem (waypoints[id_deb]->getLat(),waypoints[id_deb]->getLon(),
																	 waypoints[id_fin]->getLat(), waypoints[id_fin]->getLon());
   	ligne->setPen(QPen(couleur_routes, epaisseur_routes, Qt::SolidLine));
		this->addItem(ligne);
	}
}
