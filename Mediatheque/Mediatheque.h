//
// Created by Maëna Argaño on 25/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_MEDIATHEQUE_H
#define AP5_COO_MEDIATHEQUE_MEDIATHEQUE_H

#include "../Ressource/Ressource.h"
#include <map>
#include <vector>

class Utilisateur;

class Mediatheque {
private:
    // Pointeur vers le singleton
    static Mediatheque *singleton;
    // Toutes les ressources de la médiathèque
    std::map<int, Ressource *> ressources;
    // Recherche courante
    std::map<int, Ressource *> ressourcesCourantes;

    std::map<int, Utilisateur *> utilisateurs;
    int nextId = 1;

    // Constructeur
    Mediatheque();

public:
    // Destructeur virtuel pour Mediatheque
    ~Mediatheque() = default;

    // Accès à l’instance unique
    static Mediatheque *getInstance();

    // Accesseur
    std::map<int, Ressource *> getRessources() const;

    // Méthodes

    //ajouter une ressource
    int ajouterRessource(Ressource *r);

    void supprimerRessources(const int &pId);

    //--partie sauvegarde fichier

    std::vector<std::pair<int, const Ressource *> > snapshot() const;

    int ajouterRessourceAvecId(int id, Ressource *r);

    void chargerFichier(const std::string &nomFichier);

    void sauvFichier(const std::string &nomFichier) const;
    //--

    std::map<int, Ressource *> rechercher(const std::string &pFiltre);

    void listerRessources();

    void afficherParID(const int &pId);

    void reinitialiser();

    void viderMediatheque();

    void reserver(Utilisateur *pUtilisateur, int pId);

    void emprunter(Utilisateur *pUtilisateur, int pId);

    void rendre(Utilisateur *pUtilisateur, int pId);
};

#endif //AP5_COO_MEDIATHEQUE_MEDIATHEQUE_H
