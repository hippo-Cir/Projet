// includes VIEW
#include <QApplication>
#include <QMessageBox>
#include "LoginDialog.h"
// includes MODEL
#include <cppconn/exception.h>
#include "model/Carte.h"
#include "model/BDD.h"

int main(int argc, char **argv) {
/*  QApplication app(argc, argv);
  LoginDialog dlg;
  std::string host, base, user, pwd;

  if ( ! dlg.exec() ){ // Ouverture de la boite de dialogue
    std::cout << "Sortie de l'application\n";
    return 1;
  }
// Récupération des saisies après fermeture de la Dialog box
  dlg.getResult(host, base, user, pwd);*/
  std::cout << "Lecture base plans" << std::endl;
  Carte carte;
  try {
// Connexion BD
    BDD bdd("tcp://"+host+":3306", base, user, pwd);
// Récupération du plan
    ajoutPoints();
    carte = bdd.getContours(2);
    carte.affiche();
  }
  catch (sql::SQLException &e) {
    std::cout << "Erreur MySQL. Sortie de l'application\n";
    QMessageBox msg( QMessageBox::Critical, "Erreur mySQL",
    e.what());
    msg.exec();
    return 1;
  }
  return 0;
}
