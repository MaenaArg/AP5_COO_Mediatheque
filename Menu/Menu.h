//
// Created by Maëna Argaño on 19/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_MENU_H
#define AP5_COO_MEDIATHEQUE_MENU_H
#include <string>

class Utilisateur;

class Menu {

public:
    // Constructeur
    Menu();

    // Destructeur
    virtual ~Menu() = default;

    // Menu connexion
    void menuConnexion();
    // Connexion admin
    void demanderIdentifiants(std::string &id, std::string &mdp);
    // Menu d'accueil
    void afficherCommandes(Utilisateur* u);
    // Choix utilisateur
    std::string demanderCommande();
};

#endif //AP5_COO_MEDIATHEQUE_MENU_H