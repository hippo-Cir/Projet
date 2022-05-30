#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

#include "model/Carte.h"

class SceneCarte : public QGraphicsItem{
    Q_OBJECT
    public:
        SceneCarte(Carte &);
        void creer_items(Carte &);
    private:
        static std::map<std::string, QColor> tab_couleurs;
};
#endif
