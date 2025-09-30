//
// Created by Maëna Argaño on 18/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_CLIENT_H
#define AP5_COO_MEDIATHEQUE_CLIENT_H
#include "../Utilisateur.h"

class Client : public Utilisateur {
public:
    // Constructeur
    Client(const std::string &id, const std::string &mdp, bool connecte = false) : Utilisateur(id, mdp) {
        estConnecte = connecte;
        if (estConnecte) {
            listeCommandes = {
                {"LIST", "Lister les ressources"},
                {"SEARCH <filter>", "Filtrer les ressources"},
                {"SHOW <id>", "Afficher une ressource par ID"},
                {"CLEAR", "Réinitialiser la recherche"},
                {"RELOAD", "Recharger les données"},
                {"BORROW <id>", "Emprunter une ressource"},
                {"RETURN <id>", "Rendre une ressource"},
                {"RESERVE <id>", "Reserver une ressource"},
                {"SHOW-BORROW", "Afficher les ressources empruntées"},
                {"SHOW-RESERVE", "Afficher les ressources réservées"},
                {"LOGOUT ", "Deconnexion"},
                {"BYE", "Quitter"},
            };
        } else {
            listeCommandes = {
                {"LIST", "Lister les ressources"},
                {"SEARCH <filter>", "Filtrer les ressources"},
                {"SHOW <id>", "Afficher une ressource par ID"},
                {"CLEAR", "Réinitialiser la recherche"},
                {"RELOAD", "Recharger les données"},
                {"BYE", "Quitter"},
            };
        }
    }

    // Destructeur virtuel pour Utilisateur
    ~Client() override = default;
};

#endif //AP5_COO_MEDIATHEQUE_CLIENT_H
