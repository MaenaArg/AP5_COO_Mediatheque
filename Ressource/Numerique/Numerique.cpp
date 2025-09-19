//
// Created by GAD24 on 19/09/2025.
//

#include "Numerique.h"

using namespace std;

Numerique::Numerique(const string &id, const string &titre, const string &auteur, int anneeCreation, const string &type,
                     int taille, const string &url, statut statutRessource)
        : Ressource(id, titre, auteur, anneeCreation, statutRessource), type(type), taille(taille), url(url) {}

void Numerique::afficherInfos() const {
    cout << "Titre : " << titre
         << "Auteur : " << auteur
         << "Année de création : " << anneeCreation
         << "Type : " << type
         << "Taille : " << taille
         << "URL : " << url
         << "Statut : " << statutRessource;
}