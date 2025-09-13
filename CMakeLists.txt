cmake_minimum_required(VERSION 3.16)
project(AP5_COO_mediatheque)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AP5_COO_mediatheque
        main.cpp
        Ressource/Ressource.cpp
        Ressource/Livre.cpp
        Ressource/Revue.cpp
)
