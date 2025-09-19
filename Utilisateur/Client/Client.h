//
// Created by Maëna Argaño on 18/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_CLIENT_H
#define AP5_COO_MEDIATHEQUE_CLIENT_H
#include "../Utilisateur.h"

class Client : public Utilisateur {

    // Réutilisation du constructeur de Utilisateur
    using Utilisateur::Utilisateur;

    // Destructeur virtuel pour Utilisateur
    ~Client() override = default;
};

#endif //AP5_COO_MEDIATHEQUE_CLIENT_H