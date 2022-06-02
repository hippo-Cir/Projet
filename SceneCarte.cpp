#include "SceneCarte.h"
#include <math.h>

#define PI 3,14

std::map<std::string, QColor> SceneCarte::tab_couleurs = {{"rouge", Qt::red}, {"vert", Qt::green}};

SceneCarte::SceneCarte(Carte &carte){
	// Ajout des items graphiques dans la scène
	creer_items(carte);
	creer_waypoint(carte);
	creer_route(carte);
}

void SceneCarte::creer_items(Carte &carte){
	Contour contour;
	qreal epais = 0;// épaisseur contour
	std::string text_tooltip;
	contour = carte.getContour();
	QColor coul = tab_couleurs["rouge"];
	Point *points = contour.getPoints().data();
	int nb_points = contour.getPoints().size();
	std::cout<<nb_points<<std::endl;
	QVector<QPointF> polygone;

	for ( int i=0; i < nb_points-1; ++i ){
		polygone << QPointF(points[i].getLat(),points[i].getLon());
	//	ligne = new QGraphicsLineItem(points[i].getLat(),points[i].getLon(),points[i+1].getLat(), points[i+1].getLon());
	} // fin création point
	polygone << QPointF(points[nb_points-1].getLat(),points[0].getLon());
	QGraphicsPolygonItem* outlight = this->addPolygon(QPolygonF(polygone),QPen(QColor(1,1,1,128),0.02),QBrush(QColor(255,192,0,96)));
}

void SceneCarte::creer_waypoint(Carte &carte){
			qreal epais_wpt = 0;
			epais_wpt = 0.06;
			QColor couleur = Qt::blue;
			waypoints = carte.getWaypoints();

			for (auto &waypoints : carte.getWaypoints()){
					QGraphicsEllipseItem *point = new QGraphicsEllipseItem ( -epais_wpt/2, -epais_wpt/2,epais_wpt ,epais_wpt );
					point->setPos(waypoints->getLat(), waypoints->getLon());
					point->setPen(QPen(couleur,0,Qt::SolidLine));
					point->setBrush(QBrush(couleur,Qt::SolidPattern));
					this->addItem(point);
			}
	}

	void SceneCarte::creer_route(Carte &carte){
		//qreal epais = 0.5;
		QColor couleur = Qt::black;
		routes = carte.getRoutes();
		waypoints = carte.getWaypoints();

		QGraphicsLineItem *ligne = nullptr;

		for (auto &routes : carte.getRoutes()){
			int i_deb = routes.getIDeb();
			int i_fin = routes.getIFin();
			std::cout << ":"<<i_deb << ":"<< i_fin << std::endl;

			ligne = new QGraphicsLineItem (waypoints[i_deb]->getLat(),waypoints[i_deb]->getLon(),
						  waypoints[i_fin]->getLat(), waypoints[i_fin]->getLon());
			ligne->setPen(QPen(couleur, 0, Qt::SolidLine));

			this->addItem(ligne);

		}

	}
