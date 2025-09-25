//
// Created by Maëna Argaño on 25/09/2025.
//

#include "Mediatheque.h"

Mediatheque::Mediatheque() {
    ressources = std::map<int, Ressource>();
}

// Accesseur
std::map<int, Ressource> Mediatheque::getRessources() const { return ressources; }

// Méthodes
// Création d'une ressource en demandant les infos nécessaires. 1ère étape -> type + infos générales . 2ème étape -> infos spécifiques
void Mediatheque::creationRessources() {
    // TODO
}

// Suppression d'une ressource en demandant l'ID correspondant à l'utilisateur
void Mediatheque::supprimerRessources(const std::string &pId) {
    // TODO
}

// Mise à jour la liste des ressources présente dans la médiathèque : appelé quand création, suppression et vider médiathèque
void Mediatheque::chargerFichier(const std::string &pnomFichier) {
    // TODO
}

// Sauvegarde d'un fichier contenant les ressources en demandant le nom à l'utilisateur
void Mediatheque::sauvFichier(const std::string &pnomFichier) {
    // TODO
}

// Recherche en fonction d'un filtre demandé à l'utilisateur (peut s'appliquer à toutes les infos de la ressource)
// + Conserver la liste des résultats tant que l'utilisateur ne tape pas la commande "CLEAR"
std::map<int, Ressource> Mediatheque::rechercher(const std::string &pFiltre) {
    // TODO
}

// Affichage des infos des ressources  (compactes : titre, auteur, année) en fonction de la recherche en cours
void Mediatheque::listerRessources() {
    // TODO
}

// Affichage d'une ressource (infos) en fonction de l'ID donné par l'utilisateur
void Mediatheque::afficherParID(const std::string &pId) {
    // TODO
}

// Supprime la recherche courante
void Mediatheque::reinitialiser() {
    // TODO
}

// Suppression de toutes les ressources de la médiathèque + les ressources empruntés
void Mediatheque::viderMediatheque() {
    // TODO
}

// Permet à un utilisateur de réserver une ressource en lui demandant l'ID -> on récupère la ressource correspondante qu'on passe en paramètre
void Mediatheque::reserver(const Ressource &pRessource) {
    // TODO
}

// Permet à un utilisateur d'emprunter une ressource en lui demandant l'ID -> on récupère la ressource correspondante qu'on passe en paramètre
void Mediatheque::emprunter(const Ressource &pRessource) {
    // TODO
}

// Permet à un utilisateur de rendre une ressource en lui demandant l'ID -> on récupère la ressource correspondante qu'on passe en paramètre
void Mediatheque::rendre(const Ressource &pRessource) {
    // TODO
}