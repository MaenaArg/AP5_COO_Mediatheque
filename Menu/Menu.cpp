//
// Created by Maëna Argaño on 19/09/2025.
//

#include "Menu.h"
#include "../Utilisateur/Utilisateur.h"
#include <iostream>

Menu::Menu() {
}

void Menu::menuConnexion() {
    std::cout << "---------------------------------------- \n"
            << "Bienvenu dans votre Médiathèque ! \n"
            << "LOGIN: Connexion \n"
            << "GUEST: Continuer en tant qu'invité \n"
            << "BYE: Quitter \n"
            << "----------------------------------------"
            << std::endl;
}

void Menu::demanderIdentifiants(std::string &pId, std::string &pMdp) {
    std::cout << "Identifiant : ";
    std::cin >> pId;
    std::cout << "Mot de passe : ";
    std::cin >> pMdp;
}

void Menu::afficherCommandes(Utilisateur* pUtilisateur) {
    std::cout << "\nCommandes disponibles :" << std::endl;
    // Affichage de la liste des commandes fournie par l’utilisateur (client ou admin)
    // "commande.first" permet d'accéder à la clé de la map
    // "commande.second" permet d'accéder à la valeur de la map
    for (const auto &commande : pUtilisateur->getListeCommandes()) {
        std::cout << commande.first << " : " << commande.second << std::endl;
    }
}

std::string Menu::demanderCommande() {
    std::string commande;
    std::cout << ">>> ";
    std::cin >> commande;
    std::transform(commande.begin(), commande.end(), commande.begin(), ::toupper);
   return commande;
}


