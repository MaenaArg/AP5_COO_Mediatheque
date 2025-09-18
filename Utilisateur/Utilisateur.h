//
// Created by Maëna Argaño on 18/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_UTILISATEUR_H
#define AP5_COO_MEDIATHEQUE_UTILISATEUR_H
#include <iostream>
#include <string>

class Utilisateur {

protected :
    // Attributs
    std::string identifiant;
    std::string mdp;

public :
    // Constructeur
    Utilisateur(const std::string &pId, const std::string &pMdp) : identifiant(pId), mdp(pMdp) {
    }

    // Destructeur virtuel pour Utilisateur
    virtual ~Utilisateur() = default;

    // Accesseurs
    std::string getIdentifiant() const { return identifiant; }
    void setIdentifiant(const std::string &pId) { identifiant = pId; }

    std::string getMdp() const { return mdp; }
    void setMdp(const std::string &pMdp) { mdp = pMdp; }

    // Méthode Se Connecter avec identifiant et mdp
    virtual void seConnecter(const std::string &id, const std::string &mdp);

    // Méthode Se déconnecter
    virtual void seDeconnecter();

    // Méthode afficher les informations d'un utilisateur
    virtual void afficherInfos() {
        std::cout << "Identifiant : " << " " << identifiant << " \n" << "Mot de passe : " << mdp  << std::endl;
    }
};

#endif //AP5_COO_MEDIATHEQUE_UTILISATEUR_H