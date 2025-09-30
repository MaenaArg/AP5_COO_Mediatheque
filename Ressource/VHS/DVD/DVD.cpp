//
// Created by GAD24 on 19/09/2025.
//

#include "DVD.h"

using namespace std;

DVD::DVD(const string &titre, const string &auteur, int anneeCreation, const string &duree,
         const string &maisonProd, int nbPistes, statut statutRessource)
    : VHS(titre, auteur, anneeCreation, duree, maisonProd, statutRessource), nbPistes(nbPistes) {
}

void DVD::afficherInfos() const {
    cout << "ID : " << id << '\n'
            << "Titre : " << titre << '\n'
            << "Auteur : " << auteur << '\n'
            << "Année de création : " << anneeCreation << '\n'
            << "Nombre de pistes : " << nbPistes << '\n';
}
