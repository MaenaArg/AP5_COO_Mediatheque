#ifndef AP5_COO_MEDIATHEQUE_RESSOURCE_H
#define AP5_COO_MEDIATHEQUE_RESSOURCE_H

#include <string>
#include <iostream>

using namespace std;

class Ressource {
protected:

    enum statut {
        disponible,
        reserve,
        emprunte
    };

    string id;
    string titre;
    string auteur;
    int anneeCreation;
    statut statutRessource;

    Ressource(const string &id,
              const string &titre,
              const string &auteur,
              int anneeCreation,
              statut statutRessource)
            : id(id), titre(titre), auteur(auteur),
              anneeCreation(anneeCreation), statutRessource(statutRessource) {}

    virtual ~Ressource() {}

public:

    virtual void afficherInfos() const = 0;
};


#endif //AP5_COO_MEDIATHEQUE_RESSOURCE_H
