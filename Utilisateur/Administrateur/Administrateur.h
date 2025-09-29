//
// Created by Maëna Argaño on 18/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_ADMINISTRATEUR_H
#define AP5_COO_MEDIATHEQUE_ADMINISTRATEUR_H
#include "../Utilisateur.h"

class Administrateur : public Utilisateur {
public:
    // Constructeur
    Administrateur(const std::string &id, const std::string &mdp) : Utilisateur(id, mdp) {
        listeCommandes = {
            {"LIST", "Lister les ressources"},
            {"SEARCH", "Filtrer les ressources"},
            {"SHOW <id>", "Afficher une ressource par ID"},
            {"CLEAR", "Réinitialiser la recherche"},
            {"ADD", "Créer une ressource"},
            {"DELETE <id>", "Supprimer une ressource"},
            {"SAVE", "Sauvegarder"},
            {"LOAD", "Charger"},
            {"RESET", "Vider la médiathèque"},
            {"LOGOUT ", "Deconnexion"},
            {"BYE ", "Quitter"},
        };
    }

    // Destructeur virtuel pour Administrateur
    ~Administrateur() override = default;
};

#endif //AP5_COO_MEDIATHEQUE_ADMINISTRATEUR_H
