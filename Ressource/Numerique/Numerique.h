//
// Created by GAD24 on 19/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_NUMERIQUE_H
#define AP5_COO_MEDIATHEQUE_NUMERIQUE_H

#include "../Ressource.h"

class Numerique : public Ressource {
protected:
    std::string type;
    int taille;
    std::string url;
public:
    Numerique(const std::string &titre, const std::string &auteur, int anneeCreation, const std::string &type,
              int taille, const std::string &url, statut statutRessource = DISPONIBLE);

    const std::string& getType() const { return type; }
    int getTaille() const { return taille; }
    const std::string& getUrl() const { return url; }

    virtual ~Numerique() {}

    void afficherInfos() const;
};


#endif //AP5_COO_MEDIATHEQUE_NUMERIQUE_H
