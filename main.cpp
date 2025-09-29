#include <iostream>
#include "Mediatheque/Mediatheque.h"
#include "Utilisateur/Client/Client.h"
#include "Menu/Menu.h"
#include "Utilisateur/Administrateur/Administrateur.h"

int main() {
    Mediatheque *mediatheque = Mediatheque::getInstance();
    Menu menu;
    Utilisateur *utilisateurActuel = nullptr;
    bool boucle = true;

    while (boucle) {
        if (!utilisateurActuel) {
            // menu connexion
            Menu menu;
            menu.menuConnexion();
            std::string choix = menu.demanderCommande();

            if (choix == "LOGIN") {
                std::string id, mdp;
                menu.demanderIdentifiants(id, mdp);

                if (id == "admin" && mdp == "admin") {
                    utilisateurActuel = new Administrateur(id, mdp);
                    utilisateurActuel->seConnecter(id, mdp);
                    std::cout << "Connexion réussie, bonjour  " << id << "!\n"
                            << "----------------------------------------" << std::endl;
                } else {
                    std::cout << "Echec de connexion, identifiant ou mot de passe incorrect." << std::endl;
                }
            } else if (choix == "GUEST") {
                utilisateurActuel = new Client("invite", "");
                std::cout << "Bonjour, vous êtes un invité ! " << std::endl;
            } else if (choix == "BYE") {
                boucle = false;
            } else {
                std::cout << "Commande inconnue." << std::endl;
            }
        } else {
            // Utilisateur connecté, on affiche ses commandes
            menu.afficherCommandes(utilisateurActuel);
            std::string choix = menu.demanderCommande();

            // TODO LES AUTRES COMMANDES
            if (choix == "DELETE") {
                int id;
                if (std::cin >> id) {
                    mediatheque->supprimerRessources(id);
                } else {
                    std::cout <<  "Veuillez fournir un identifiant après DELETE. Syntaxe : DELETE <id>\n";
                    std::cin.clear(); // Réinitialisation de l'entrée cin
                    std::cin.ignore(200, '\n'); // vider la ligne entrée
                }
            } else if (choix == "SHOW") {
                int id;
                if (std::cin >> id) {
                    mediatheque->afficherParID(id);
                } else {
                    std::cout <<  "Veuillez fournir un identifiant après SHOW. Syntaxe : SHOW <id>\n";
                    std::cin.clear(); // Réinitialisation de l'entrée cin
                    std::cin.ignore(200, '\n'); // vider la ligne entrée
                }
            } else if (choix == "RESET") {
                mediatheque->viderMediatheque();
            } else if (choix == "LOGOUT") {
                utilisateurActuel->seDeconnecter();
                delete utilisateurActuel;
                // Plus personne de connecté
                utilisateurActuel = nullptr;
            } else if (choix == "BYE") {
                boucle = false;
            } else {
                std::cout << "Commande [TODO]." << std::endl;
            }
        }
    }
    delete utilisateurActuel;
    return 0;
}
