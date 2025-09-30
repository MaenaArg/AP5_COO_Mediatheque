//
// Created by GAD24 on 13/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_REVUE_H
#define AP5_COO_MEDIATHEQUE_REVUE_H

#include "../Livre.h"
#include "map"

class Revue : public Livre {
private:
    std::string editeur;
    std::map<int, std::string> articles;
    int nbArticle;

public:
    Revue(const std::string &titre, const std::string &auteur, int anneeCreation, int nbPages,
          const std::string &collection, const std::string &resume, const std::string &editeur,
          const std::map<int, std::string> &articles,
          int nbArticle, statut statutRessource = DISPONIBLE);

    const std::string& getEditeur() const { return editeur; }
    const std::map<int, std::string>& getArticles() const { return articles; }
    int getNbArticles() const { return nbArticle; }

    void afficherInfos() const override;
};


#endif //AP5_COO_MEDIATHEQUE_REVUE_H
