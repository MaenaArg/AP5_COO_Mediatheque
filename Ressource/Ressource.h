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

    int id;
    static int nextId;
    string titre;
    string auteur;
    int anneeCreation;
    statut statutRessource;

public:
    static const char *statutToCString(statut s);

    static std::string statutToString(statut s); // si tu préfères std::string

    Ressource(const string &titre,
              const string &auteur,
              int anneeCreation,
              statut statutRessource)
            : id(nextId++), titre(titre), auteur(auteur),
              anneeCreation(anneeCreation), statutRessource(statutRessource) {}

    virtual ~Ressource() = default;

    virtual void afficherInfos() const = 0;
};

#endif //AP5_COO_MEDIATHEQUE_RESSOURCE_H
