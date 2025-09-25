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
    DVD(const string &id, const string &titre, const string &auteur, int anneeCreation, const string &duree,
        const string &maisonProd, int nbPistes, statut statutRessource = statut::disponible);

    void afficherInfos() const override;
};


#endif //AP5_COO_MEDIATHEQUE_DVD_H
