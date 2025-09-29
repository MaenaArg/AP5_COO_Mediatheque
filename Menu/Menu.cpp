//
// Created by Maëna Argaño on 19/09/2025.
//

#include "Menu.h"
#include "../Utilisateur/Utilisateur.h"
#include "../Ressource/Livre/Livre.h"
#include "../Ressource/Livre/Revue/Revue.h"
#include "../Ressource/CD/CD.h"
#include "../Ressource/VHS/VHS.h"
#include "../Ressource/VHS/DVD/DVD.h"
#include "../Ressource/Numerique/Numerique.h"
#include <iostream>
#include <algorithm>
#include <limits>

Menu::Menu() {
}

void Menu::menuConnexion() {
    std::cout << "---------------------------------------- \n"
              << "Bienvenu dans votre Médiathèque ! \n"
              << "LOGIN: Connexion \n"
              << "GUEST: Continuer en tant qu'invité \n"
              << "BYE: Quitter \n"
              << "----------------------------------------"
              << std::endl;
}

void Menu::demanderIdentifiants(std::string &pId, std::string &pMdp) {
    std::cout << "Identifiant : ";
    std::cin >> pId;
    std::cout << "Mot de passe : ";
    std::cin >> pMdp;
}

Ressource *Menu::demanderInfoRessources() {
    // -- lecture robuste du type (accepte "1" ou "livre", "numérique", etc.)
    std::string typeStr;
    std::cout << "Type de la ressource à créer : \n"
              << "1 Livre\n"
              << "2 Revue\n"
              << "3 CD\n"
              << "4 VHS\n"
              << "5 DVD\n"
              << "6 Numerique\n> ";
    std::getline(std::cin >> std::ws, typeStr);
    int type = 0;
    if (typeStr == "1" || typeStr == "livre") type = 1;
    else if (typeStr == "2" || typeStr == "revue") type = 2;
    else if (typeStr == "3" || typeStr == "cd") type = 3;
    else if (typeStr == "4" || typeStr == "vhs") type = 4;
    else if (typeStr == "5" || typeStr == "dvd") type = 5;
    else if (typeStr == "6" || typeStr == "numerique" || typeStr == "numerique " || typeStr == "num") type = 6;
    else { std::cout << "Choix invalide.\n"; return nullptr; }

    // -- infos communes
    std::string titre, auteur;
    int anneeCreation = 0;

    std::cout << "Titre : ";
    std::getline(std::cin, titre);

    std::cout << "Auteur : ";
    std::getline(std::cin, auteur);

    std::cout << "Année de création : ";
    while (!(std::cin >> anneeCreation)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Veuillez entrer un nombre pour l'année : ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // -- dispatch
    switch (type) {
        case 1: return demanderInfoLivre(titre, auteur, anneeCreation);
        case 2: return demanderInfoRevue(titre, auteur, anneeCreation);
        case 3: return demanderInfoCd(titre, auteur, anneeCreation);
        case 4: return demanderInfoVhs(titre, auteur, anneeCreation);
        case 5: return demanderInfoDVD(titre, auteur, anneeCreation);
        case 6: return demanderInfoNumerique(titre, auteur, anneeCreation);
        default: std::cout << "Choix invalide.\n"; return nullptr;
    }
}

Ressource *Menu::demanderInfoLivre(std::string titre, std::string auteur, int annee) {
    std::string nbPages;
    std::string collection;
    std::string resume;

    std::cout << "Type de la ressource à créer : \n"
              << "1 Livre\n"
              << "Nombre de pages :\n";
    std::getline(std::cin, nbPages);
    std::cout << "Collection : ";
    std::getline(std::cin, collection);
    std::cout << "Résumé : ";
    std::getline(std::cin, resume);

    return new Livre(titre, auteur, annee, stoi(nbPages), collection, resume);
}

Ressource *Menu::demanderInfoRevue(std::string titre, std::string auteur, int annee) {
    std::string nbPages;
    std::string collection;
    std::string resume;
    std::string editeur;
    std::map<int, std::string> articles;
    std::string nbArticles;

    std::cout << "Type de la ressource à créer : \n"
              << "2 Revue\n"
              << "Nombre de pages :\n";
    std::getline(std::cin, nbPages);
    std::cout << "Collection : ";
    std::getline(std::cin, collection);
    std::cout << "Résumé : ";
    std::getline(std::cin, resume);
    std::cout << "Éditeur :\n";
    std::getline(std::cin, editeur);
    std::cout << "Nombre d'articles : ";
    std::getline(std::cin, nbArticles);
    std::cout << "Articles : ";

    for (int i = 1; i <= stoi(nbArticles); ++i) {
        std::string titreArticle;
        std::cout << "  - Titre de l'article " << i << " : ";
        std::getline(std::cin, titreArticle);
        if (titreArticle.empty()) {
            --i;
            continue;
        }
        articles[i] = titreArticle;
    }

    return new Revue(titre, auteur, annee, stoi(nbPages), collection, resume, editeur, articles, stoi(nbArticles));
}

Ressource *Menu::demanderInfoCd(std::string titre, std::string auteur, int annee) {
    std::string duree;
    std::string nbPistes;
    std::string maisonProd;

    std::cout << "Type de la ressource à créer : \n"
              << "3 CD \n"
              << "Durée du CD :\n";
    std::getline(std::cin, duree);
    std::cout << "Nombre de pistes: : ";
    std::getline(std::cin, nbPistes);
    std::cout << "Maison de production : ";
    std::getline(std::cin, maisonProd);

    return new CD(titre, auteur, annee, duree, stoi(nbPistes), maisonProd);
}

Ressource *Menu::demanderInfoVhs(std::string titre, std::string auteur, int annee) {
    std::string duree;
    std::string maisonProd;

    std::cout << "Type de la ressource à créer : \n"
              << "4 VHS \n"
              << "Durée de la VHS :\n";
    std::getline(std::cin, duree);
    std::cout << "Maison de production : ";
    std::getline(std::cin, maisonProd);

    return new VHS(titre, auteur, annee, duree, maisonProd);
}

Ressource *Menu::demanderInfoDVD(std::string titre, std::string auteur, int annee) {
    std::string duree;
    std::string maisonProd;
    std::string nbPistes;

    std::cout << "Type de la ressource à créer : \n"
              << "5 DVD \n"
              << "Durée du DVD :\n";
    std::getline(std::cin, duree);
    std::cout << "Maison de production : ";
    std::getline(std::cin, maisonProd);
    std::cout << "Nombre de pistes : ";
    std::getline(std::cin, nbPistes);

    return new DVD(titre, auteur, annee, duree, maisonProd, stoi(nbPistes));
}

Ressource *Menu::demanderInfoNumerique(std::string titre, std::string auteur, int annee) {
    std::string type;
    std::string taille;
    std::string url;

    std::cout << "Type de la ressource à créer : \n"
              << "6 Numerique \n"
              << "Type de contenu numérique :\n";
    std::getline(std::cin, type);
    std::cout << "taille de la ressource : ";
    std::getline(std::cin, taille);
    std::cout << "url : ";
    std::getline(std::cin, url);

    return new Numerique(titre, auteur, annee, type, stoi(taille), url);
}

void Menu::afficherCommandes(Utilisateur *pUtilisateur) {
    std::cout << "\nCommandes disponibles :" << std::endl;
    // Affichage de la liste des commandes fournie par l’utilisateur (client ou admin)
    // "commande.first" permet d'accéder à la clé de la map
    // "commande.second" permet d'accéder à la valeur de la map
    for (const auto &commande: pUtilisateur->getListeCommandes()) {
        std::cout << commande.first << " : " << commande.second << std::endl;
    }
}

std::string Menu::demanderCommande() {
    std::string commande;
    std::cout << ">>> ";
    std::cin >> commande;
    std::transform(commande.begin(), commande.end(), commande.begin(), ::toupper);
    return commande;
}


