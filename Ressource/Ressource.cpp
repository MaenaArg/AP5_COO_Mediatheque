//
// Created by GAD24 on 13/09/2025.
//

#include "Ressource.h"

using namespace std;

void Ressource::reserver() {
    disponible = false;
}

void Ressource::emprunter() {
    disponible = false;
}

void Ressource::rendre() {
    disponible = true;
}