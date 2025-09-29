//
// Created by GAD24 on 13/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_REVUE_H
#define AP5_COO_MEDIATHEQUE_REVUE_H

#include "../Livre.h"
#include <map>

using namespace std;

class Revue : public Livre {
private:
    string editeur;
    map<int, string> articles;
    int nbArticle;

public:
    Revue(const string &titre, const string &auteur, int anneeCreation, int nbPages,
          const string &collection, const string &resume, const string &editeur, const map<int, string> &articles,
          int nbArticle, statut statutRessource = DISPONIBLE);

    void afficherInfos() const override;
};


#endif //AP5_COO_MEDIATHEQUE_REVUE_H
