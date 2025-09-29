//
// Created by Maëna Argaño on 18/09/2025.
//

#ifndef AP5_COO_MEDIATHEQUE_UTILISATEUR_H
#define AP5_COO_MEDIATHEQUE_UTILISATEUR_H
#include <map>
#include <string>
#include <vector>

class Ressource;

class Utilisateur {
protected :
    // Attributs
    std::string identifiant;
    std::string mdp;
    bool estConnecte = false;
    std::map<int, Ressource *> listEmprunt;
    std::map<int, Ressource *> listReserve;
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

    std::map<int, Ressource *> getListReserve() const;

    std::vector<std::pair<std::string, std::string> > getListeCommandes() const;

    // Méthode Se Connecter avec identifiant et mdp
    virtual void seConnecter(const std::string &pId, const std::string &pMdp);

    // Méthode Se déconnecter
    virtual void seDeconnecter();

    // Méthode afficher les informations d'un utilisateur
    virtual void afficherInfos();

    // Méthodes communes :

    void afficherCommandes() const;

    // Méthodes qui vérifie si une ressource est réservée par cet utilisateur
    bool rechercheResResaParID(int pId) const;

    // Méthode ajout d'une ressource dans la liste des réservations
    void ajouterReservation(int pId, Ressource* pRessource);

    // Méthode suppression d'une ressource de la liste des réservations
    void supprimerReservation(int pId);

    // Méthode d'ajout d'une ressource dans la liste des emprunts
    void ajouterEmprunt(int pId, Ressource* pRessource);

    // Méthode de suppression d'un emprunt dans la liste correspondante
    void supprimerEmprunt(int pID);

    // Vider la liste des ressources empruntées
    void viderEmprunts();

    // Affichage des listes d'emprunts et réservations
    void afficherEmprunts();
    void afficherReservations();
};

#endif //AP5_COO_MEDIATHEQUE_UTILISATEUR_H
