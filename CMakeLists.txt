cmake_minimum_required(VERSION 3.16)
project(AP5_COO_mediatheque)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AP5_COO_mediatheque
        main.cpp
        Ressource/Ressource.cpp
        Ressource/Livre/Livre.cpp
        Ressource/Livre/Revue/Revue.cpp
        Ressource/CD/CD.cpp
        Ressource/CD/CD.h
        Ressource/VHS/VHS.cpp
        Ressource/VHS/VHS.h
        Ressource/VHS/DVD/DVD.cpp
        Ressource/VHS/DVD/DVD.h
        Ressource/Numerique/Numerique.cpp
        Ressource/Numerique/Numerique.h
        Utilisateur/Utilisateur.cpp
        Utilisateur/Utilisateur.h
        Utilisateur/Administrateur/Administrateur.h
        Utilisateur/Client/Client.h
        Menu/Menu.cpp
        Menu/Menu.h
)
