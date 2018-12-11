cmake_minimum_required(VERSION 3.13)
project(client)

set(CMAKE_CXX_STANDARD 14)

add_executable(client main.cpp formes/Forme.h formes/croix/Croix.cpp formes/croix/Croix.h formes/Forme.cpp formes/exceptions/FormeException.cpp formes/exceptions/FormeException.h formes/rond/Rond.cpp formes/rond/Rond.h formes/Formes.h)