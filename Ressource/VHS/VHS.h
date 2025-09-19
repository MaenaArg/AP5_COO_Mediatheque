//
// Created by GAD24 on 19/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_VHS_H
#define AP5_COO_MEDIATHEQUE_VHS_H

#include "../Ressource.h"

using namespace std;

class VHS : public Ressource {
protected:
    string duree;
    string maisonProd;
public:
    VHS(const string &id, const string &titre, const string &auteur, int anneeCreation, const string &duree,
        const string &maisonProd, statut statutRessource = statut::disponible);

    virtual ~VHS() {}

    void afficherInfos() const override;
};


#endif //AP5_COO_MEDIATHEQUE_VHS_H
