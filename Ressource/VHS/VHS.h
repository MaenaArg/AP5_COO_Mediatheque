//
// Created by GAD24 on 19/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_VHS_H
#define AP5_COO_MEDIATHEQUE_VHS_H

#include "../Ressource.h"

class VHS : public Ressource {
protected:
    std::string duree;
    std::string maisonProd;
public:
    VHS(const std::string &titre, const std::string &auteur, int anneeCreation, const std::string &duree,
        const std::string &maisonProd, statut statutRessource = DISPONIBLE);

    const std::string& getDuree() const { return duree; }
    const std::string& getMaisonProd() const { return maisonProd; }

    virtual ~VHS() {}

    void afficherInfos() const override;
};


#endif //AP5_COO_MEDIATHEQUE_VHS_H
