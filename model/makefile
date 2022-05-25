all: testcarte.exe libBDD.a
libBDD.a: BDD.o
	ar rUuv libBDD.a BDD.o
testcarte.exe: testBDDCarte1.o BDD.o
	g++ testBDDCarte1.o BDD.o -lmysqlcppconn -o testcarte.exe
testBDDCarte1.o: testBDDCarte1.cpp BDD.h Carte.h Contour.h Route.h Ville.h Waypoint.h
	g++ -std=c++11 -c testBDDCarte1.cpp
BDD.o: BDD.cpp BDD.h Carte.h Contour.h Route.h Ville.h Waypoint.h Point.h
	g++ -fPIE -std=c++11 -c BDD.cpp
clean:
	rm *.o testcarte.exe
