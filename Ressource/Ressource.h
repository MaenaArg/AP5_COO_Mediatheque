#ifndef AP5_COO_MEDIATHEQUE_RESSOURCE_H
#define AP5_COO_MEDIATHEQUE_RESSOURCE_H

#include <string>
#include <iostream>

using namespace std;

class Ressource {
protected:
    int id;
    static int nextId;
    string titre;
    string auteur;
    int anneeCreation;


public:
    enum statut {
        DISPONIBLE,
        RESERVE,
        EMPRUNTE
    };
    statut statutRessource;
    static const char *statutToCString(statut s);

    static std::string statutToString(statut s); // si tu préfères std::string

    Ressource(const string &titre,
              const string &auteur,
              int anneeCreation,
              statut statutRessource)
            : id(nextId++), titre(titre), auteur(auteur),
              anneeCreation(anneeCreation), statutRessource(statutRessource) {}

    virtual ~Ressource() = default;

    // Accesseurs
    int getID() const;
    string getTitre() const;
    string getAuteur() const;
    statut getStatutRessource() const;
    void setStatutRessource(const statut &pStatut);

    virtual void afficherInfos() const = 0;
};

#endif //AP5_COO_MEDIATHEQUE_RESSOURCE_H
