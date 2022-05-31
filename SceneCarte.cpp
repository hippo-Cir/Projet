#include "SceneCarte.h"

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

	QGraphicsLineItem *ligne = nullptr;

	for ( int i=0; i < nb_points-1; ++i ){

		ligne = new QGraphicsLineItem (points[i].getLat(),points[i].getLon(),points[i+1].getLat(), points[i+1].getLon());
	//	line = QGraphicsPolygonItem* outlight = scene->addPolygon(QPolygonF(points),QPen(QColor(255,255,255,128)),QBrush(QColor(255,192+(rand()%64 - 32),0,96)));

		ligne->setPen(QPen(coul, 0, Qt::SolidLine));

		this->addItem(ligne);

	} // fin création point
}
	void SceneCarte::creer_waypoint(Carte &carte){
		std::vector<Waypoint *> waypoints = carte.getWaypoints();
		qreal epaisseur=0;
		std::string text_tooltip;

		QColor coul = tab_couleurs["green"];
		epaisseur = 0.1;
		for (auto &waypoints : carte.getWaypoints()){

			QGraphicsEllipseItem *point = new QGraphicsEllipseItem ( -epaisseur/2, -epaisseur/2, epaisseur, epaisseur);
				point->setPos(waypoints->getLon(), waypoints->getLat());
				point->setPen(QPen(coul,0,Qt::SolidLine));
				point->setBrush(QBrush(coul,Qt::SolidPattern));
				this->addItem(point);

		}


		 // fin création point
}
