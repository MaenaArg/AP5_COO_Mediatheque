//
// Created by GAD24 on 13/09/2025.
//

#include "Ressource.h"

const char *Ressource::statutToCString(statut s) {
    switch (s) {
        case DISPONIBLE:
            return "disponible";
        case RESERVE:
            return "reservé";
        case EMPRUNTE:
            return "emprunté";
        default:
            return "inconnu";
    }
}

std::string Ressource::statutToString(statut s) {
    return std::string(statutToCString(s));
}

int Ressource::nextId = 1;

int Ressource::getID() const { return id; }
string Ressource::getTitre() const { return titre; }
string Ressource::getAuteur() const { return auteur; }

Ressource::statut Ressource::getStatutRessource() const { return statutRessource; }
void Ressource::setStatutRessource(const statut &pStatut) { statutRessource = pStatut; }
