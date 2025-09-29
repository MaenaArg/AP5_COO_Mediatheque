//
// Created by GAD24 on 13/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_LIVRE_H
#define AP5_COO_MEDIATHEQUE_LIVRE_H

#include "../Ressource.h"

using namespace std;

class Livre : public Ressource {
protected:
    int nbPages;
    string collection;
    string resume;
public:
    Livre(const std::string &titre, const std::string &auteur, int anneeCreation, int nbPages,
          const std::string &collection, const std::string &resume, statut statutRessource = statut::disponible);

    virtual ~Livre() {}

    void afficherInfos() const override;
};


#endif //AP5_COO_MEDIATHEQUE_LIVRE_H
