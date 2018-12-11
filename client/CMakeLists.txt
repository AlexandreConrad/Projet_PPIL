cmake_minimum_required(VERSION 3.13)
project(client)

set(CMAKE_CXX_STANDARD 14)

add_executable(client main.cpp formes/Forme.h formes/croix/Croix.cpp formes/croix/Croix.h formes/croix/CroixException.cpp formes/croix/CroixException.h formes/Forme.cpp formes/FormeException.cpp formes/FormeException.h formes/rond/Rond.cpp formes/rond/Rond.h formes/Formes.h formes/rond/RondException.cpp formes/rond/RondException.h)
