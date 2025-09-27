//
// Created by GAD24 on 18/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_CD_H
#define AP5_COO_MEDIATHEQUE_CD_H

#include "../Ressource.h"

using namespace std;

class CD : public Ressource {
protected:
    int nbPistes;
    string duree;
    string maisonProd;
public:
    CD(const string &titre, const string &auteur, int anneeCreation, int nbPistes,
       const string &duree, const string &maisonProd, statut statutRessource = statut::disponible);

    virtual ~CD() {}

    void afficherInfos() const override;
};


#endif //AP5_COO_MEDIATHEQUE_CD_H
