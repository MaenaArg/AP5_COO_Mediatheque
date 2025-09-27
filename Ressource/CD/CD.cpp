//
// Created by GAD24 on 18/09/2025.
//

#include "CD.h"

using namespace std;

CD::CD(const string &titre, const string &auteur, int anneeCreation, int nbPistes,
       const string &duree, const string &maisonProd, statut statutRessource)
    : Ressource(titre, auteur, anneeCreation, statutRessource), duree(duree), nbPistes(nbPistes),
      maisonProd(maisonProd) {
}

void CD::afficherInfos() const {
    cout << "ID : " << id << '\n'
            << "Titre : " << titre << '\n'
            << "Auteur : " << auteur << '\n'
            << "Année de création : " << anneeCreation << '\n'
            << "Nombre de pistes : " << nbPistes << '\n'
            << "Durée : " << duree << '\n'
            << "Maison de production : " << maisonProd << '\n'
            << "Statut : " << statutRessource << '\n';
}
