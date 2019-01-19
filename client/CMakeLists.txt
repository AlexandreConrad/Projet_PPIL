cmake_minimum_required(VERSION 3.13)
project(client-ppil)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(chargeurs)
include_directories(couleurs)
include_directories(formes)
include_directories(formes/complexes)
include_directories(formes/simples)
include_directories(sauvegardes)
include_directories(surfaces)
include_directories(transformations)
include_directories(vecteurs)

add_executable(client-ppil
        chargeurs/ChargeurCercle.cpp
        chargeurs/ChargeurCercle.h
        chargeurs/ChargeurForme.h
        chargeurs/ChargeurFormeComposee.cpp
        chargeurs/ChargeurFormeComposee.h
        chargeurs/ChargeurPolygone.cpp
        chargeurs/ChargeurPolygone.h
        chargeurs/ChargeurSegment.cpp
        chargeurs/ChargeurSegment.h
        couleurs/Couleur.cpp
        couleurs/Couleur.h
        formes/complexes/FormeComposee.cpp
        formes/complexes/FormeComposee.h
        formes/simples/Cercle.cpp
        formes/simples/Cercle.h
        formes/simples/FormeSimple.cpp
        formes/simples/FormeSimple.h
        formes/simples/Polygone.cpp
        formes/simples/Polygone.h
        formes/simples/Segment.cpp
        formes/simples/Segment.h
        formes/simples/Triangle.cpp
        formes/simples/Triangle.h
        formes/Forme.cpp
        formes/Forme.h
        sauvegardes/Sauvegarde.h
        sauvegardes/SauvegardeTexte.cpp
        sauvegardes/SauvegardeTexte.h
        surfaces/Surface.h
        surfaces/SurfaceJava.cpp
        surfaces/SurfaceJava.h
        transformations/Homothetie.cpp
        transformations/Homothetie.h
        transformations/Rotation.cpp
        transformations/Rotation.h
        transformations/Transformation.cpp
        transformations/Transformation.h
        transformations/Translation.cpp
        transformations/Translation.h
        vecteurs/Vecteur2D.cpp
        vecteurs/Vecteur2D.h
        CMakeLists.txt
        main.cpp
        sockets/Socket.cpp
        sockets/Socket.h)

if (WIN32)
    target_link_libraries(client-ppil wsock32 ws2_32)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif ()