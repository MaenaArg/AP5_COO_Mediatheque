//
// Created by GAD24 on 19/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_NUMERIQUE_H
#define AP5_COO_MEDIATHEQUE_NUMERIQUE_H

#include "../Ressource.h"

using namespace std;

class Numerique : public Ressource {
protected:
    string type;
    int taille;
    string url;
public:
    Numerique(const string &id, const string &titre, const string &auteur, int anneeCreation, const string &type,
              int taille, const string &url, statut statutRessource = statut::disponible);

    virtual ~Numerique() {}

    void afficherInfos() const override;
};


#endif //AP5_COO_MEDIATHEQUE_NUMERIQUE_H
