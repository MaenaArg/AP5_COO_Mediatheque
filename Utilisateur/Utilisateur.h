//
// Created by Maëna Argaño on 18/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_UTILISATEUR_H
#define AP5_COO_MEDIATHEQUE_UTILISATEUR_H
#include <iostream>
#include <map>
#include <string>

class Ressource;

class Utilisateur {
protected :
    // Attributs
    std::string identifiant;
    std::string mdp;
    bool estConnecte = false;
    std::map<int, Ressource *> listEmprunt;
    std::vector<std::pair<std::string, std::string> > listeCommandes;

public:
    // Constructeur
    Utilisateur(const std::string &pId, const std::string &pMdp);

    // Destructeur virtuel pour Utilisateur
    virtual ~Utilisateur() = default;

    // Accesseurs
    std::string getIdentifiant() const;

    void setIdentifiant(const std::string &pId);

    std::string getMdp() const;

    void setMdp(const std::string &pMdp);

    bool getEstConnecte() const;

    void setEstConnecte(const bool &pEstConnecte);

    std::map<int, Ressource *> getListEmprunt() const;

    std::vector<std::pair<std::string, std::string> > getListeCommandes() const;

    // Méthode Se Connecter avec identifiant et mdp
    virtual void seConnecter(const std::string &id, const std::string &pMdp);

    // Méthode Se déconnecter
    virtual void seDeconnecter();

    // Méthode afficher les informations d'un utilisateur
    virtual void afficherInfos();

    // Méthodes communes
    void afficherCommandes() const;

    // Vider la liste des ressources empruntées
    void viderEmprunts();
};

#endif //AP5_COO_MEDIATHEQUE_UTILISATEUR_H
