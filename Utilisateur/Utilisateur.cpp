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

// Liste des ressources empruntées
std::map<int, Ressource *> Utilisateur::getListEmprunt() const {
    return listEmprunt;
}

// Liste des commandes
std::vector<std::pair<std::string, std::string>> Utilisateur::getListeCommandes() const { return listeCommandes; }

// Méthode afficher les informations d'un utilisateur
void Utilisateur::afficherInfos() {
    std::cout << "Identifiant : " << " " << identifiant << " \n"
              << "Mot de passe : " << mdp << std::endl;
}

// Méthode Se Connecter avec identifiant et mdp
void Utilisateur::seConnecter(const std::string &pId, const std::string &pMdp) {
    if (pId == identifiant && pMdp == mdp && !estConnecte) {
        estConnecte = true;
        /*std::cout << "Connexion réussie, bonjour  " << identifiant << "!" << std::endl;*/
    } else {
        estConnecte = false;
        /*std::cout << "Echec de connexion, identifiant ou mot de passe incorrect.";*/
    }
}

// Méthode Se déconnecter
void Utilisateur::seDeconnecter() {
    if (estConnecte) {
        estConnecte = false;
        /*std::cout << "Déconnexion réussie, au revoir " << identifiant << " !";

        Menu menu;
        menu.menuConnexion();*/
    } else {
        std::cout << "Echec de deconnexion.";
    }
}

void Utilisateur::afficherCommandes() const {
    std::cout << "\nCommandes disponibles :\n";
    for (const auto& cmd : listeCommandes) {
        std::cout << "  " << cmd.first << " - " << cmd.second << std::endl;
    }
}

void Utilisateur::viderEmprunts() {
    listEmprunt.clear(); // Suppression des pointeurs, pas la ressource réelle -> pas de double suppression
}
