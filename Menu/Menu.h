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

    Ressource* demanderInfoLivre(string titre, string auteur, int anneeCreation);

    Ressource* demanderInfoRevue(string titre, string auteur, int anneeCreation);

    Ressource* demanderInfoCd(string titre, string auteur, int anneeCreation);

    Ressource* demanderInfoVhs(string titre, string auteur, int anneeCreation);

    Ressource* demanderInfoDVD(string titre, string auteur, int annee);

    Ressource* demanderInfoNumerique(string titre, string auteur, int anneeCreation);

    // Menu d'accueil
    void afficherCommandes(Utilisateur *u);

    // Choix utilisateur
    std::string demanderCommande();
};

#endif //AP5_COO_MEDIATHEQUE_MENU_H