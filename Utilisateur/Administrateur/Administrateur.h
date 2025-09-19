//
// Created by Maëna Argaño on 18/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_ADMINISTRATEUR_H
#define AP5_COO_MEDIATHEQUE_ADMINISTRATEUR_H
#include "../Utilisateur.h"

class Administrateur : public Utilisateur {

public:
    // Réutilisation du constructeur de Utilisateur
    using Utilisateur::Utilisateur;

    // Destructeur virtuel pour Administrateur
    ~Administrateur() override = default;
};

#endif //AP5_COO_MEDIATHEQUE_ADMINISTRATEUR_H