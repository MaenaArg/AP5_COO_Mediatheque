//
// Created by Maëna Argaño on 18/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_CLIENT_H
#define AP5_COO_MEDIATHEQUE_CLIENT_H
#include <iostream>
#include <string>

class Client {

    // Constructeur
    Client(const std::string &pId, const std::string &pMdp) ;

    // Destructeur virtuel pour Utilisateur
    virtual ~Client() = default;
};

#endif //AP5_COO_MEDIATHEQUE_CLIENT_H