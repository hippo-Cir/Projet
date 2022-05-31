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
    private:
        static std::map<std::string, QColor> tab_couleurs;
};
#endif
