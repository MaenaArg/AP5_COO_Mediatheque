//
// Created by Maëna Argaño on 19/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_MENU_H
#define AP5_COO_MEDIATHEQUE_MENU_H

#include <string>
#include "../Ressource/Ressource.h"

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

    //création de ressource
    Ressource* demanderInfoRessources();

    Ressource* demanderInfoLivre(std::string titre, std::string auteur, int anneeCreation);

    Ressource* demanderInfoRevue(std::string titre, std::string auteur, int anneeCreation);

    Ressource* demanderInfoCd(std::string titre, std::string auteur, int anneeCreation);

    Ressource* demanderInfoVhs(std::string titre, std::string auteur, int anneeCreation);

    Ressource* demanderInfoDVD(std::string titre, std::string auteur, int annee);

    Ressource* demanderInfoNumerique(std::string titre, std::string auteur, int anneeCreation);

    // Menu d'accueil
    void afficherCommandes(Utilisateur *u);

    // Choix utilisateur
    std::string demanderCommande();
};

#endif //AP5_COO_MEDIATHEQUE_MENU_H