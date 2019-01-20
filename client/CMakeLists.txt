cmake_minimum_required(VERSION 3.13)
project(client-ppil)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src/chargeurs)
include_directories(src/couleurs)
include_directories(src/formes)
include_directories(src/formes/complexes)
include_directories(src/formes/simples)
include_directories(src/sauvegardes)
include_directories(src/surfaces)
include_directories(src/transformations)
include_directories(src/vecteurs)

add_executable(client-ppil
        src/chargeurs/ChargeurCercle.cpp
        src/chargeurs/ChargeurCercle.h
        src/chargeurs/ChargeurForme.h
        src/chargeurs/ChargeurFormeComposee.cpp
        src/chargeurs/ChargeurFormeComposee.h
        src/chargeurs/ChargeurPolygone.cpp
        src/chargeurs/ChargeurPolygone.h
        src/chargeurs/ChargeurSegment.cpp
        src/chargeurs/ChargeurSegment.h
        src/couleurs/Couleur.cpp
        src/couleurs/Couleur.h
        src/formes/complexes/FormeComposee.cpp
        src/formes/complexes/FormeComposee.h
        src/formes/simples/Cercle.cpp
        src/formes/simples/Cercle.h
        src/formes/simples/FormeSimple.cpp
        src/formes/simples/FormeSimple.h
        src/formes/simples/Polygone.cpp
        src/formes/simples/Polygone.h
        src/formes/simples/Segment.cpp
        src/formes/simples/Segment.h
        src/formes/simples/Triangle.cpp
        src/formes/simples/Triangle.h
        src/formes/Forme.cpp
        src/formes/Forme.h
        src/sauvegardes/Sauvegarde.h
        src/sauvegardes/SauvegardeTexte.cpp
        src/sauvegardes/SauvegardeTexte.h
        src/surfaces/Surface.h
        src/surfaces/SurfaceJava.cpp
        src/surfaces/SurfaceJava.h
        src/transformations/Homothetie.cpp
        src/transformations/Homothetie.h
        src/transformations/Rotation.cpp
        src/transformations/Rotation.h
        src/transformations/Transformation.cpp
        src/transformations/Transformation.h
        src/transformations/Translation.cpp
        src/transformations/Translation.h
        src/vecteurs/Vecteur2D.cpp
        src/vecteurs/Vecteur2D.h
        src/main.cpp
        src/sockets/Socket.cpp
        src/sockets/Socket.h)

if (WIN32)
    target_link_libraries(client-ppil wsock32 ws2_32)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif ()