#ifndef AP5_COO_MEDIATHEQUE_RESSOURCE_H
#define AP5_COO_MEDIATHEQUE_RESSOURCE_H

#include <string>
#include <iostream>

using namespace std;

class Ressource {
protected:
    string id;
    string titre;
    string auteur;
    int anneeCreation;
    bool disponible;

    Ressource(const string &id,
              const string &titre,
              const string &auteur,
              int anneeCreation,
              bool disponible = true)
            : id(id), titre(titre), auteur(auteur),
              anneeCreation(anneeCreation), disponible(disponible) {}

    virtual ~Ressource() {}

public:

    virtual void afficherInfos() const = 0;

    virtual void reserver();

    virtual void rendre();

    virtual void emprunter();
};


#endif //AP5_COO_MEDIATHEQUE_RESSOURCE_H
