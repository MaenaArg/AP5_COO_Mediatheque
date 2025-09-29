//
// Created by GAD24 on 19/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_DVD_H
#define AP5_COO_MEDIATHEQUE_DVD_H

#include "../VHS.h"

class DVD : public VHS {
private:
    int nbPistes;

public:
    DVD(const std::string &titre, const std::string &auteur, int anneeCreation, const std::string &duree,
        const std::string &maisonProd, int nbPistes, statut statutRessource = DISPONIBLE);

    int getNbPistes() const { return nbPistes; }

    void afficherInfos() const override;
};


#endif //AP5_COO_MEDIATHEQUE_DVD_H
