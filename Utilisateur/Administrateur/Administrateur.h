//
// Created by Maëna Argaño on 18/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_ADMINISTRATEUR_H
#define AP5_COO_MEDIATHEQUE_ADMINISTRATEUR_H
#include "../Utilisateur.h"


class Administrateur : Utilisateur {

public:
    // Constructeur
    Administrateur(const std::string &pId, const std::string &pMdp);

    // Destructeur virtuel pour Utilisateur
    virtual ~Administrateur() = default;
};


#endif //AP5_COO_MEDIATHEQUE_ADMINISTRATEUR_H