//
// Created by GAD24 on 19/09/2025.
//

#include "DVD.h"

using namespace std;

DVD::DVD(const string &id, const string &titre, const string &auteur, int anneeCreation, const string &duree,
         const string &maisonProd, int nbPistes, statut statutRessource)
        : VHS(id, titre, auteur, anneeCreation, duree, maisonProd, statutRessource), nbPistes(nbPistes) {}

void DVD::afficherInfos() const {
    cout << "Titre : " << titre
         << "Auteur : " << auteur
         << "Année de création : " << anneeCreation
         << "Nombre de pistes : " << nbPistes;
}