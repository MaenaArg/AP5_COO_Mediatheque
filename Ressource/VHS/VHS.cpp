//
// Created by GAD24 on 19/09/2025.
//

#include "VHS.h"

using namespace std;

VHS::VHS(const string &id, const string &titre, const string &auteur, int anneeCreation, const string &duree,
         const string &maisonProd, statut statutRessource)
        : Ressource(id, titre, auteur, anneeCreation, statutRessource), duree(duree), maisonProd(maisonProd) {}

void VHS::afficherInfos() const {
    cout << "Titre : " << titre << '\n'
         << "Auteur : " << auteur << '\n'
         << "Année de création : " << anneeCreation << '\n'
         << "Durée : " << duree << '\n'
         << "Maison de production : " << maisonProd << '\n'
         << "Statut : " << statutRessource << '\n';
}