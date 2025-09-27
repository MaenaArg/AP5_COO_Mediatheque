//
// Created by Maëna Argaño on 25/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_MEDIATHEQUE_H
#define AP5_COO_MEDIATHEQUE_MEDIATHEQUE_H
#include "../Ressource/Ressource.h"
#include <map>


class Mediatheque {
private:
    // Pointeur vers le singleton
    static Mediatheque *singleton;
    std::map<int, Ressource *> ressources;

    // Constructeur
    Mediatheque();

public:
    // Destructeur virtuel pour Mediatheque
    ~Mediatheque() = default;

    // Accès à l’instance unique
    static Mediatheque *getInstance();

    // Accesseur
    std::map<int, Ressource *> getRessources() const;

    // Méthodes
    void creationRessources();

    void supprimerRessources(const std::string &pId);

    void chargerFichier(const std::string &pnomFichier);

    void sauvFichier(const std::string &pnomFichier);

    std::map<int, Ressource> rechercher(const std::string &pFiltre);

    void listerRessources();

    void afficherParID(const int &pId);

    void reinitialiser();

    void viderMediatheque();

    void reserver(const Ressource &pRessource);

    void emprunter(const Ressource &pRessource);

    void rendre(const Ressource &pRessource);
};

#endif //AP5_COO_MEDIATHEQUE_MEDIATHEQUE_H
