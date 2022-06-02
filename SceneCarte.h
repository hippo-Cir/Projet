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
        void creer_items(Carte &);
        void creer_waypoint(Carte &);
        void creer_route(Carte &);
    private:
        static std::map<std::string, QColor> tab_couleurs;
        std::vector<Waypoint *> waypoints;
        std::vector<Route> routes;
};
#endif
