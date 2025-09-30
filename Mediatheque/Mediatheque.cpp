//
// Created by Maëna Argaño on 25/09/2025.
//

#include "Mediatheque.h"
#include "../Utilisateur/Utilisateur.h"
#include "../Ressource/Ressource.h"
#include "../sauvegarde/sauvegarde.h"
#include <iostream>
#include <iomanip>
#include "../Ressource/Livre/Livre.h"
#include "../Ressource/Livre/Revue/Revue.h"
#include "../Ressource/CD/CD.h"
#include "../Ressource/VHS/VHS.h"
#include "../Ressource/VHS/DVD/DVD.h"
#include "../Ressource/Numerique/Numerique.h"

// Initialisation du singleton
Mediatheque *Mediatheque::singleton = nullptr;

Mediatheque::Mediatheque() = default;

Mediatheque *Mediatheque::getInstance() {
    if (!singleton) {
        singleton = new Mediatheque();
    }
    return singleton;
}

// Accesseur
std::map<int, Ressource *> Mediatheque::getRessources() const {
    return ressources;
}

// Méthodes
// Création d'une ressource en demandant les infos nécessaires. 1ère étape -> type + infos générales . 2ème étape -> infos spécifiques
int Mediatheque::ajouterRessource(Ressource *r) {
    if (!r) return -1;
    const int id = nextId++;
    ressources[id] = r;
    return id;
}

// Suppression d'une ressource en demandant l'ID correspondant à l'utilisateur
void Mediatheque::supprimerRessources(const int &pId) {
    auto it = ressources.find(pId);

    if (it != ressources.end()) {
        // Libérer la mémoire de la ressource
        delete it->second;

        // Supprimer la ressource de la map
        ressources.erase(it);

        std::cout << "La ressource d'ID " << pId << " a été supprimée." << std::endl;
    } else {
        std::cout << "Aucune ressource trouvée avec l'ID : " << pId << std::endl;
    }
}

std::vector<std::pair<int, const Ressource *> > Mediatheque::snapshot() const {
    std::vector<std::pair<int, const Ressource *> > v;
    v.reserve(ressources.size());
    for (const auto &kv: ressources) v.emplace_back(kv.first, kv.second);
    return v;
}

int Mediatheque::ajouterRessourceAvecId(int id, Ressource *r) {
    if (!r) return -1;
    ressources[id] = r;
    if (id >= nextId) nextId = id + 1; // garde la continuité des IDs
    return id;
}

// Mise à jour la liste des ressources présente dans la médiathèque : appelé quand création, suppression et vider médiathèque et ajouter les données du fichier
void Mediatheque::chargerFichier(const std::string &nomFichier) {
    sauvegarde::load(nomFichier, *this);
}

// Sauvegarde d'un fichier contenant les ressources en demandant le nom à l'utilisateur
void Mediatheque::sauvFichier(const std::string &nomFichier) const {
    sauvegarde::save(nomFichier, *this);
}

// Recherche en fonction d'un filtre demandé à l'utilisateur (peut s'appliquer à toutes les infos de la ressource)
// + Conserver la liste des résultats tant que l'utilisateur ne tape pas la commande "CLEAR"
std::map<int, Ressource *> Mediatheque::rechercher(const std::string &pFiltre) {
    std::map<int, Ressource *> ressourcesTotales;

    // Première recherche -> on part de la totalité des ressources
    if (ressourcesCourantes.empty()) {
        ressourcesTotales = ressources;
    } else {
        ressourcesTotales = ressourcesCourantes;
    }

    ressourcesCourantes.clear();

    for (auto &pair: ressourcesTotales) {
        Ressource *ressource = pair.second;

        // Conversion des champs en string
        std::string idStr = std::to_string(ressource->getID());
        std::string titreStr = ressource->getTitre();
        std::string auteurStr = ressource->getAuteur();
        std::string anneeStr = std::to_string(ressource->getAnneeCreation());
        std::string statutStr;

        switch (ressource->getStatutRessource()) {
            case Ressource::statut::DISPONIBLE:
                statutStr = "DISPONIBLE";
                break;
            case Ressource::statut::RESERVE:
                statutStr = "RESERVE";
                break;
            case Ressource::statut::EMPRUNTE:
                statutStr = "EMPRUNTE";
                break;
        }

        // Comparaison du filtre avec toutes les données des ressources
        if (titreStr.find(pFiltre) != std::string::npos ||
            auteurStr.find(pFiltre) != std::string::npos ||
            idStr.find(pFiltre) != std::string::npos ||
            anneeStr.find(pFiltre) != std::string::npos ||
            statutStr.find(pFiltre) != std::string::npos) {
            ressourcesCourantes[pair.first] = ressource;
        }
    }

    if (ressourcesCourantes.empty()) {
        std::cout << "Aucun résultat trouvé pour " << pFiltre << std::endl;
    } else {
        std::cout << "Résultats trouvés :" << std::endl;
        for (auto &pair: ressourcesCourantes) {
            pair.second->afficherInfos();
        }
    }

    return ressourcesCourantes;
}

// Affichage des infos des ressources  (compactes : titre, auteur, année) en fonction de la recherche en cours
void Mediatheque::listerRessources() {
    using std::cout;
    using std::left;
    using std::setw;

    if (ressources.empty()) {
        cout << "(aucune ressource)\n";
        return;
    }

    auto typeDe = [](const Ressource *r) -> const char * {
        if (dynamic_cast<const Revue *>(r)) return "Revue";
        if (dynamic_cast<const Livre *>(r)) return "Livre";
        if (dynamic_cast<const DVD *>(r)) return "DVD";
        if (dynamic_cast<const VHS *>(r)) return "VHS";
        if (dynamic_cast<const CD *>(r)) return "CD";
        if (dynamic_cast<const Numerique *>(r)) return "Numerique";
        return "Ressource";
    };

    auto statutStr = [](Ressource::statut s) -> const char * {
        switch (s) {
            case Ressource::statut::DISPONIBLE:
                return "DISPONIBLE";
            case Ressource::statut::RESERVE:
                return "RESERVE";
            case Ressource::statut::EMPRUNTE:
                return "EMPRUNTE";
            default:
                return "INCONNU";
        }
    };

    // En-têtes
    cout << left
            << setw(6) << "ID"
            << setw(12) << "Type"
            << setw(34) << "Titre"
            << setw(24) << "Auteur"
            << setw(8) << "Annee"
            << "Statut" << '\n';

    cout << std::string(6 + 12 + 34 + 24 + 8 + 6, '-') << '\n';

    // Lignes
    for (const auto &kv: ressources) {
        int id = kv.first;
        const Ressource *r = kv.second;

        cout << left
                << setw(6) << id
                << setw(12) << typeDe(r)
                << setw(34) << r->getTitre()
                << setw(24) << r->getAuteur()
                << setw(8) << r->getAnneeCreation()
                << statutStr(r->getStatut())
                << '\n';
    }
}

// Affichage d'une ressource (infos) en fonction de l'ID donné par l'utilisateur
void Mediatheque::afficherParID(const int &pId) {
    auto it = ressources.find(pId);

    if (it != ressources.end()) {
        it->second->afficherInfos();
    } else {
        std::cout << "Aucune ressource trouvée avec l'ID : " << pId << std::endl;
    }
}

// Supprime la recherche courante
void Mediatheque::reinitialiser() {
    ressourcesCourantes.clear();
    std::cout << "Recherche réinitialisée !" << std::endl;
}

// Suppression de toutes les ressources de la médiathèque + les ressources empruntées
void Mediatheque::viderMediatheque() {
    // On parcourt toutes les ressources et on les supprime
    for (auto &pair: ressources) {
        delete pair.second; // Libération de la mémoire du pointeur Ressource* -> évite les fuites mémoire
    }
    // On vide la map
    ressources.clear();

    for (auto &pair: utilisateurs) {
        pair.second->viderEmprunts(); // Libération de la mémoire du pointeur Ressource* -> évite les fuites mémoire
    }

    std::cout << "La médiathèque est maintenant vide !" << std::endl;
}

// Permet à un utilisateur de réserver une ressource en lui demandant l'ID
void Mediatheque::reserver(Utilisateur *pUtilisateur, int pId) {
    if (!pUtilisateur || !pUtilisateur->getEstConnecte()) {
        std::cout << "Erreur : aucun utilisateur connecté." << std::endl;
        return;
    }

    auto it = ressources.find(pId);
    if (it != ressources.end()) {
        Ressource *ressource = it->second;

        if (ressource->getStatutRessource() == Ressource::statut::DISPONIBLE) {
            ressource->setStatutRessource(Ressource::statut::RESERVE);

            // Ajout de la ressource dans la liste de réservation de l’utilisateur
            pUtilisateur->ajouterReservation(pId,
                                             ressource);
            // Ajout de la ressource dans la liste des réservations du client

            std::cout << "La ressource " << pId << " a été réservée." << std::endl;
        } else {
            std::cout << "Impossible de réserver la ressource " << pId << ", elle est déjà réservée ou empruntée." <<
                    std::endl;
        }
    } else {
        std::cout << "Aucune ressource trouvée avec l'ID : " << pId << std::endl;
    }
}

// Permet à un utilisateur d'emprunter une ressource en lui demandant l'ID
void Mediatheque::emprunter(Utilisateur *pUtilisateur, int pId) {
    if (!pUtilisateur || !pUtilisateur->getEstConnecte()) {
        std::cout << "Erreur : aucun utilisateur connecté." << std::endl;
        return;
    }

    auto it = ressources.find(pId);
    if (it != ressources.end()) {
        Ressource *ressource = it->second;

        // Si la resource est disponible ou qu'elle a été réservée par l'utilisateur en cours
        if (ressource->getStatutRessource() == Ressource::statut::DISPONIBLE ||
            ressource->getStatutRessource() == Ressource::statut::RESERVE &&
            pUtilisateur->rechercheResResaParID(ressource->getID())) {
            ressource->setStatutRessource(Ressource::statut::EMPRUNTE);

            // Ajout de la ressource dans la liste d’emprunts de l’utilisateur
            pUtilisateur->ajouterEmprunt(pId, ressource); // Ajout de la ressource dans la liste des emprunts du client
            pUtilisateur->supprimerReservation(
                pId); // Suppression de la ressource réservée de la liste des réservations

            std::cout << "La ressource " << pId << " a été empruntée." << std::endl;
        } else {
            std::cout << "Impossible d'emprunter : ressource déjà empruntée ou réservée." << std::endl;
        }
    } else {
        std::cout << "Aucune ressource trouvée avec l'ID : " << pId << std::endl;
    }
}

// Permet à un utilisateur de rendre une ressource en lui demandant l'ID
void Mediatheque::rendre(Utilisateur *pUtilisateur, int pId) {
    if (!pUtilisateur || !pUtilisateur->getEstConnecte()) {
        std::cout << "Erreur : aucun utilisateur connecté." << std::endl;
        return;
    }
    auto it = ressources.find(pId);
    if (it != ressources.end()) {
        Ressource *ressource = it->second;

        if (ressource->getStatutRessource() == Ressource::statut::EMPRUNTE) {
            ressource->setStatutRessource(Ressource::statut::DISPONIBLE);

            // Retirer la ressource de la liste des emprunts
            pUtilisateur->supprimerEmprunt(pId);

            std::cout << "La ressource " << pId << " a été rendue." << std::endl;
        } else {
            std::cout << "Impossible de rendre : la ressource n'est pas empruntée." << std::endl;
        }
    } else {
        std::cout << "Aucune ressource trouvée avec l'ID : " << pId << std::endl;
    }
}
