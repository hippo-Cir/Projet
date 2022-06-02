#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

#include "model/Carte.h"

class SceneCarte : public QGraphicsScene{
    Q_OBJECT
    public:
        SceneCarte(Carte &);
        void afficher_contours(Carte &);
        void afficher_waypoints(Carte &);
        void afficher_routes(Carte &);
    private:
        static std::map<std::string, QColor> tab_couleurs;
        std::vector<Waypoint *> waypoints;
        std::vector<Route> routes;
        QVector<QPointF> polygone;
};
#endif
