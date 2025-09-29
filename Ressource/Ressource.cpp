//
// Created by GAD24 on 13/09/2025.
//

#include "Ressource.h"

const char *Ressource::statutToCString(Ressource::statut s) {
    switch (s) {
        case Ressource::disponible:
            return "disponible";
        case Ressource::reserve:
            return "reservé";
        case Ressource::emprunte:
            return "emprunté";
        default:
            return "inconnu";
    }
}

std::string Ressource::statutToString(Ressource::statut s) {
    return std::string(statutToCString(s));
}

int Ressource::nextId = 1;