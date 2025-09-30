//
// Created by GAD24 on 29/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_SAUVEGARDE_H
#define AP5_COO_MEDIATHEQUE_SAUVEGARDE_H

#include <string>
#include "Mediatheque/Mediatheque.h"


namespace Sauvegarde {
    // Enregistre toutes les ressources (Livre, Revue, CD, VHS, DVD, Numérique)
    bool save(const std::string& path, const Mediatheque& m);

    // Recharge le fichier (remplace le contenu courant de la médiathèque)
    bool load(const std::string& path, Mediatheque& m);
}


#endif //AP5_COO_MEDIATHEQUE_SAUVEGARDE_H
