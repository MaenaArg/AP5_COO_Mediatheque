cmake_minimum_required(VERSION 4.0)
project(AP5_COO_mediatheque)

set(CMAKE_CXX_STANDARD 20)

add_executable(AP5_COO_mediatheque main.cpp
        Utilisateur/Utilisateur.cpp
        Utilisateur/Utilisateur.h
        Utilisateur/Administrateur/Administrateur.cpp
        Utilisateur/Administrateur/Administrateur.h
        Utilisateur/Client/Client.cpp
        Utilisateur/Client/Client.h)
