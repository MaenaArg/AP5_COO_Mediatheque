//
// Created by GAD24 on 13/09/2025.
//

#include "Revue.h"

using namespace std;

Revue::Revue(const string &id, const string &titre, const string &auteur, int anneeCreation, int nbPages,
             const string &collection, const string &resume, const string &editeur, const map<int, string> &articles,
             int nbArticle, statut statutRessource)
        : Livre(id, titre, auteur, anneeCreation, nbPages, collection, resume, statutRessource), editeur(editeur),
          articles(articles), nbArticle(nbArticle) {}

void Revue::afficherInfos() const {
    cout << titre
         << auteur
         << anneeCreation
         << editeur
         << nbArticle;
    if (!articles.empty()) {
        for (const auto &[page, article]: articles) {
            cout << article << '\n';
        }
    }
}