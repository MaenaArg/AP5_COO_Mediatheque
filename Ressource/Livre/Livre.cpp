//
// Created by GAD24 on 13/09/2025.
//

#include "Livre.h"

using namespace std;

Livre::Livre(const string &id, const string &titre, const string &auteur, int anneeCreation, int nbPages,
             const string &collection, const string &resume, statut statutRessource)
        : Ressource(id, titre, auteur, anneeCreation, statutRessource), nbPages(nbPages), collection(collection),
          resume(resume) {}

void Livre::afficherInfos() const {
    cout << "Titre : " << titre
         << "Auteur : " << auteur
         << "Année de création : " << anneeCreation
         << "Nombre de pages : " << nbPages
         << "Collection : " << collection
         << "Résumé : " << resume
         << "Statut : " << statutRessource;
}