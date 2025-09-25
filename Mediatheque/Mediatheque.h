//
// Created by Maëna Argaño on 25/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_MEDIATHEQUE_H
#define AP5_COO_MEDIATHEQUE_MEDIATHEQUE_H
#include "../Ressource/Ressource.h"
#include <map>


class Mediatheque {
private:
    std::map<int, Ressource> ressources;

public:
    // Constructeur
    Mediatheque();

    // Destructeur virtuel pour Mediatheque
    virtual ~Mediatheque() = default;

    // Accesseur
    std::map<int, Ressource> getRessources() const ;

    // Méthodes
    virtual void creationRessources();
    virtual void supprimerRessources();
    virtual void chargerFichier(const std::string &pnomFichier);
    virtual void sauvFichier(const std::string &pnomFichier);
    virtual std::map<int, Ressource> rechercher(const std::string &pFiltre);
    virtual void listerRessources();
    virtual void afficherParID(const std::string &id);
    virtual void reinitialiser();
    virtual void viderMediatheque();
    virtual void reserver(const Ressource &pRessource);
    virtual void emprunter(const Ressource &pRessource);
    virtual void rendre(const Ressource &pRessource);
};

#endif //AP5_COO_MEDIATHEQUE_MEDIATHEQUE_H
