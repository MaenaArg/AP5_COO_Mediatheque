//
// Created by GAD24 on 13/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_LIVRE_H
#define AP5_COO_MEDIATHEQUE_LIVRE_H

#include "../Ressource.h"

class Livre : public Ressource {
protected:
    int nbPages;
    std::string collection;
    std::string resume;
public:
    Livre(const std::string &titre, const std::string &auteur, int anneeCreation, int nbPages,
          const std::string &collection, const std::string &resume, statut statutRessource = DISPONIBLE);

    int getNbPages() const { return nbPages; }
    const std::string& getCollection() const { return collection; }
    const std::string& getResume() const { return resume; }

    virtual ~Livre() {}

    void afficherInfos() const override;
};


#endif //AP5_COO_MEDIATHEQUE_LIVRE_H
