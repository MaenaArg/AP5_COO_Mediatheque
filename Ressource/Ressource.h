#ifndef AP5_COO_MEDIATHEQUE_RESSOURCE_H
#define AP5_COO_MEDIATHEQUE_RESSOURCE_H

#include <string>
#include <iostream>

class Ressource {
protected:
    int id;
    static int nextId;
    std::string titre;
    std::string auteur;
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

    Ressource(const std::string &titre,
              const std::string &auteur,
              int anneeCreation,
              statut statutRessource)
            : id(nextId++), titre(titre), auteur(auteur),
              anneeCreation(anneeCreation), statutRessource(statutRessource) {}

    virtual ~Ressource() = default;

    // Accesseurs
    int getID() const;
    const std::string& getTitre() const { return titre; }
    const std::string& getAuteur() const { return auteur; }
    int getAnneeCreation() const { return anneeCreation; }
    statut getStatut() const { return statutRessource; }
    void setStatut(statut s) { statutRessource = s; }
    statut getStatutRessource() const ;
    void setStatutRessource(const statut &pStatut);

    virtual void afficherInfos() const = 0;
};

#endif //AP5_COO_MEDIATHEQUE_RESSOURCE_H
