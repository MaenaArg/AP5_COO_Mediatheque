//
// Created by GAD24 on 18/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_CD_H
#define AP5_COO_MEDIATHEQUE_CD_H

#include "../Ressource.h"

class CD : public Ressource {
protected:
    int nbPistes;
    std::string duree;
    std::string maisonProd;
public:
    CD(const std::string &titre, const std::string &auteur, int anneeCreation, const std::string &duree, int nbPistes,
       const std::string &maisonProd, statut statutRessource = DISPONIBLE);

    const std::string& getDuree() const { return duree; }
    int getNbPistes() const { return nbPistes; }
    const std::string& getMaisonProd() const { return maisonProd; }

    virtual ~CD() {}

    void afficherInfos() const override;
};


#endif //AP5_COO_MEDIATHEQUE_CD_H
