cmake_minimum_required(VERSION 3.16)
project(AP5_COO_mediatheque LANGUAGES CXX)

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
        Mediatheque/Mediatheque.cpp
        Mediatheque/Mediatheque.h
)

# Inclure le dossier racine pour les headers (optionnel mais pratique)
target_include_directories(AP5_COO_mediatheque PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Encodage UTF-8 pour MinGW/GCC (ce bloc doit être EN DEHORS de add_executable)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(AP5_COO_mediatheque PRIVATE
            -finput-charset=UTF-8
            -fexec-charset=UTF-8
    )
endif ()

# Sur Windows : éviter les macros min/max et charger Windows.h “léger” si tu l’utilises
if (WIN32)
    target_compile_definitions(AP5_COO_mediatheque PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX)
endif ()
