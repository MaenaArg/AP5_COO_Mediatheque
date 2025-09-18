//
// Created by GAD24 on 18/09/2025.
//

#include "CD.h"

using namespace std;

CD::CD(const string &id, const string &titre, const string &auteur, int anneeCreation, int nbPistes,
       const string &duree, const string &maisonProd, statut statutRessource)
        : Ressource(id, titre, auteur, anneeCreation, statutRessource),
          duree(duree), nbPistes(nbPistes), maisonProd(maisonProd) {}

void CD::afficherInfos() const {
    cout << titre
         << auteur
         << anneeCreation
         << nbPistes
         << duree
         << maisonProd
         << statutRessource;
}