#include "SceneCarte.h"

std::map<std::string, QColor> SceneCarte::tab_couleurs = {{"rouge", Qt::red}, {"vert", Qt::green}};

SceneCarte::SceneCarte(Carte &carte){
	// Ajout des items graphiques dans la scène
	creer_items(carte);
}

void SceneCarte::creer_items(Carte &carte){

	qreal epais = 0;// épaisseur contour
	std::string text_tooltip;

	for (auto &contour : carte.getContour() ){
		QColor coul = tab_couleurs[Qt::green];
		epais = 2;
		Point *points = contour.getPoints().data();
		int nb_points = contour.getPoints().size();

    if ( !nb_points ) continue;

		QGraphicsLineItem *ligne = nullptr;

		for ( int i=0; i < nb_points-1; ++i ){

			ligne = new QGraphicsLineItem (points[i].getLon(),points[i].getLat(),points[i+1].getLon(), points[i+1].getLat());
			ligne->setPen(QPen(coul, epais, Qt::SolidLine));

			std::string  text_tooltip = contour.getInfos();

			ligne->setToolTip(QString::fromStdString(text_tooltip));

			this->addItem(ligne);



			QGraphicsEllipseItem *point = new QGraphicsEllipseItem ( -epais/2, -epais/2, epais, epais);

			point->setPos(points[i].getLon(), points[i].getLat());

			point->setPen(QPen(Qt::black,0,Qt::SolidLine));

			point->setBrush(QBrush(Qt::gray,Qt::SolidPattern));



			text_tooltip = points[i].getInfos();

			point->setToolTip(QString::fromStdString(text_tooltip));



			point->setParentItem(ligne);

		} // fin création point

		// Dernier point

		QGraphicsEllipseItem *point = new QGraphicsEllipseItem ( -epais/2, -epais/2, epais, epais);

		point->setPos(points[nb_points-1].getLon(), points[nb_points-1].getLat());

		point->setPen(QPen(Qt::black,0,Qt::SolidLine));

		point->setBrush(QBrush(Qt::gray,Qt::SolidPattern));


		text_tooltip = points[nb_points-1].getInfos();

		point->setToolTip(QString::fromStdString(text_tooltip));

		point->setParentItem(ligne);


	}// fin création contour

	// Matérialisation du point origine de la scène (taille = épaisseur contour)

	qreal taille_o = epais;

	QGraphicsEllipseItem *origine = new QGraphicsEllipseItem(-taille_o/2,-taille_o/2,taille_o,taille_o);

	origine->setPos(0,0);

	origine->setPen(QPen(Qt::black,0,Qt::SolidLine));

	this->addItem(origine);

}
