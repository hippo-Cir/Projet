######################################################################
# Automatically generated by qmake (3.0) jeu. juin 2 10:00:20 2022
######################################################################

TEMPLATE = app
TARGET = vraiproj
INCLUDEPATH += .

# Input
HEADERS += FenetrePrincipale.h \
           GrandeVue.h \
           LoginDialog.h \
           MiniVue.h \
           Pathfinding.h \
           SceneCarte.h
SOURCES += FenetrePrincipale.cpp \
           LoginDialog.cpp \
           main.cpp \
           Pathfinding.cpp \
           SceneCarte.cpp

           QT += widgets
           QMAKE_CXXFLAGS += -std=c++11 -g
           LIBS += model/libBDD.a
           LIBS += -lmysqlcppconn
