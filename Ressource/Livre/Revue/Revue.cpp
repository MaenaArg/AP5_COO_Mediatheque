//
// Created by GAD24 on 13/09/2025.
//

#include "Revue.h"

Revue::Revue(const std::string &titre, const std::string &auteur, int anneeCreation, int nbPages,
             const std::string &collection, const std::string &resume, const std::string &editeur, const std::map<int, std::string> &articles,
             int nbArticle, statut statutRessource)
    : Livre(titre, auteur, anneeCreation, nbPages, collection, resume, statutRessource), editeur(editeur),
      articles(articles), nbArticle(nbArticle) {
}

void Revue::afficherInfos() const {
    std::cout << "ID : " << id << '\n'
            << "Titre : " << titre << '\n'
            << "Auteur : " << auteur << '\n'
            << "Année de création : " << anneeCreation << '\n'
            << "Éditeur : " << editeur << '\n'
            << "Statut : " << statutRessource << '\n'
            << "Nombre d'articles : " << nbArticle << '\n';
    if (!articles.empty()) {
        for (const auto &[page, article]: articles) {
            std::cout << "  - p." << page << " : " << article << '\n';
        }
    }
}
