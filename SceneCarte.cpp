#include "SceneCarte.h"
#include <math.h>


std::map<std::string, QColor> SceneCarte::tab_couleurs = {{"rouge", Qt::red}, {"vert", Qt::green}};

SceneCarte::SceneCarte(Carte &carte){
	// Ajout des items graphiques dans la scène
	creer_items(carte);
	creer_waypoint(carte);
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
	QGraphicsPolygonItem* outlight = this->addPolygon(QPolygonF(polygone),QPen(QColor(255,255,255,128)),QBrush(QColor(255,192,0,96)));
}
void SceneCarte::creer_waypoint(Carte &carte){
			qreal epais_wpt=0;
			epais_wpt = 0.1;
			QColor couleur = tab_couleurs["noir"];
			waypoints = carte.getWaypoints();

			for (auto &waypoints : carte.getWaypoints()){
					QGraphicsEllipseItem *point = new QGraphicsEllipseItem ( -epais_wpt/2, -epais_wpt/2,epais_wpt ,epais_wpt );
					point->setPos(waypoints->getLat(), waypoints->getLon());
					point->setPen(QPen(couleur,0,Qt::SolidLine));
					point->setBrush(QBrush(couleur,Qt::SolidPattern));
					this->addItem(point);
			}
	}
