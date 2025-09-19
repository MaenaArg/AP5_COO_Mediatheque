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
    cout << "Titre : " << titre << '\n'
         << "Auteur : " << auteur << '\n'
         << "Année de création : " << anneeCreation << '\n'
         << "Nombre de pages : " << nbPages << '\n'
         << "Collection : " << collection << '\n'
         << "Résumé : " << resume << '\n'
         << "Statut : " << statutRessource << '\n';
}