# /*************************************************************************
#                           	struct Coordinates
#                              -------------------
#     début                : 9 mai 2023
#     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
#     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
# *************************************************************************/

//---------- Interface de la classe Coordinates (fichier Coordinates.h) ----------------

#ifndef Coordinates_H
#define Coordinates_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <iostream>

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <Coordinates>
// 
//------------------------------------------------------------------------

typedef struct Coordinates{

    //---------------------------------------------------------- Attributs

    float latitude;
    float longitude;

    float distanceTo(struct Coordinates coord) {
        return (latitude-coord.latitude)*(latitude-coord.latitude) + (longitude-coord.longitude)*(longitude-coord.longitude);
    } 

}Coordinates;

#endif