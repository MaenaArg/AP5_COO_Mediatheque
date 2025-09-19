//
// Created by Maëna Argaño on 18/09/2025.
//

#include "Utilisateur.h"
#include <iostream>
#include <string>

Utilisateur::Utilisateur(const std::string &pId, const std::string &pMdp) : identifiant(pId), mdp(pMdp) {
}

// Accesseurs
// Identifiant
std::string Utilisateur::getIdentifiant() const { return identifiant; }
void Utilisateur::setIdentifiant(const std::string &pId) { identifiant = pId; }

// Mot de passe
std::string Utilisateur::getMdp() const { return mdp; }
void Utilisateur::setMdp(const std::string &pMdp) { mdp = pMdp; }

// Est connecté
bool Utilisateur::getEstConnecte() const { return estConnecte; }
void Utilisateur::setEstConnecte(const bool &pEstConnecte) { estConnecte = pEstConnecte; }

// Méthode afficher les informations d'un utilisateur
void Utilisateur::afficherInfos() {
    std::cout << "Identifiant : " << " " << identifiant << " \n" << "Mot de passe : " << mdp << std::endl;
}

// Méthode Se Connecter avec identifiant et mdp
void Utilisateur::seConnecter(const std::string &id, const std::string &pMdp) {
    if (id == identifiant && pMdp == mdp && !estConnecte) {
        estConnecte = true;
        std::cout << "Connexion réussie, bonjour  " << id << "!" << std::endl;
    } else {
        std::cout << "Echec de connexion.";
    }
}

// Méthode Se déconnecter
void Utilisateur::seDeconnecter() {
    if (estConnecte) {
        estConnecte = false;
        std::cout << "Déconnexion réussie, au revoir " << identifiant << " !";
    } else {
        std::cout << "Echec de deconnexion.";
    }
}
