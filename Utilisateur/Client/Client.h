//
// Created by Maëna Argaño on 18/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_CLIENT_H
#define AP5_COO_MEDIATHEQUE_CLIENT_H
#include "../Utilisateur.h"

class Client : public Utilisateur {

public:
    // Constructeur
    Client(const std::string &id, const std::string &mdp) : Utilisateur(id, mdp) {
        listeCommandes = {
            {"LIST", "Lister les ressources"},
            {"SEARCH", "Filtrer les ressources"},
            {"SHOW", "Afficher une ressource par ID"},
            {"CLEAR", "Réinitialiser la recherche"},
            {"RELOAD", "Recharger les données"},
            {"BORROW", "Emprunter une ressource"},
            {"RETURN", "Rendre une ressource"},
            {"RESERVE", "Reserver une ressource"},
            {"BYE", "Quitter"},
        };
    }

    // Destructeur virtuel pour Utilisateur
    ~Client() override = default;
};

#endif //AP5_COO_MEDIATHEQUE_CLIENT_H
