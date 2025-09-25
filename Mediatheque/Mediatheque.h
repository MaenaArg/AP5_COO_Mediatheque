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
    Mediatheque() ;

    // Destructeur virtuel pour Mediatheque
    ~Mediatheque() = default;

    // Accesseur
    std::map<int, Ressource> getRessources() const ;

    // Méthodes
    static void creationRessources();
    static void supprimerRessources(const std::string &pId);
    static void chargerFichier(const std::string &pnomFichier);
    static void sauvFichier(const std::string &pnomFichier);
    static std::map<int, Ressource> rechercher(const std::string &pFiltre);
    static void listerRessources();
    static void afficherParID(const std::string &pId);
    static void reinitialiser();
    static void viderMediatheque();
    static void reserver(const Ressource &pRessource);
    static void emprunter(const Ressource &pRessource);
    static void rendre(const Ressource &pRessource);
};

#endif //AP5_COO_MEDIATHEQUE_MEDIATHEQUE_H
