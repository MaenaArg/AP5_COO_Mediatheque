//
// Created by Maëna Argaño on 18/09/2025.
//

#include "Utilisateur.h"
#include <iostream>
#include <string>

#include "Ressource/Ressource.h"

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

// Liste des ressources reservée
std::map<int, Ressource *> Utilisateur::getListReserve() const {
    return listReserve;
}

// Liste des commandes
std::vector<std::pair<std::string, std::string> > Utilisateur::getListeCommandes() const { return listeCommandes; }

// Méthode afficher les informations d'un utilisateur
void Utilisateur::afficherInfos() {
    std::cout << "Identifiant : " << identifiant << " \n"
              << "Mot de passe : " << mdp << std::endl;
}

// Méthode Se Connecter avec identifiant et mdp
void Utilisateur::seConnecter(const std::string &pId, const std::string &pMdp) {
    if (pId == identifiant && pMdp == mdp && !estConnecte) {
        estConnecte = true;
    }
}

// Méthode Se déconnecter
void Utilisateur::seDeconnecter() {
    if (estConnecte) {
        estConnecte = false;
    } else {
        std::cout << "Echec de deconnexion.\n";
    }
}

void Utilisateur::afficherCommandes() const {
    std::cout << "\nCommandes disponibles :\n";
    for (const auto &cmd: listeCommandes) {
        std::cout << "  " << cmd.first << " - " << cmd.second << std::endl;
    }
}

bool Utilisateur::rechercheResResaParID(int pID) const {
    return listReserve.find(pID) != listReserve.end();
}

void Utilisateur::ajouterReservation(int pID, Ressource *pRessource) {
    listReserve[pID] = pRessource;
}

void Utilisateur::supprimerReservation(int pID) {
    listReserve.erase(pID);
}

void Utilisateur::ajouterEmprunt(int pID, Ressource *pRessource) {
    listEmprunt[pID] = pRessource;
}

void Utilisateur::supprimerEmprunt(int pID) {
    listEmprunt.erase(pID);
}


void Utilisateur::viderEmprunts() {
    listEmprunt.clear(); // Suppression des pointeurs, pas la ressource réelle -> pas de double suppression
}

void Utilisateur::afficherEmprunts() {
    if (listEmprunt.empty()) {
        std::cout << "Aucun emprunt." << std::endl;
    } else {
        std::cout << "Liste des emprunts :" << std::endl;
        for (const auto& pair : listEmprunt) {
            Ressource* ressource = pair.second;
            if (ressource) {
                std::cout << "ID: " << pair.first << "\n"
                          << "Titre: " << ressource->getTitre() << "\n"
                          << "Auteur: " << ressource->getAuteur()
                          << std::endl;
            }
        }
    }
}
void Utilisateur::afficherReservations() {
    if (listReserve.empty()) {
        std::cout << "Aucune réservation." << std::endl;
    } else {
        std::cout << "Liste des réservations :" << std::endl;
        for (const auto& pair : listReserve) {
            Ressource* ressource = pair.second;
            if (ressource) {
                std::cout << "ID: " << pair.first << "\n"
                          << "Titre: " << ressource->getTitre() << "\n"
                          << "Auteur: " << ressource->getAuteur()
                          << std::endl;
            }
        }
    }
}