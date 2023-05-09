# /*************************************************************************
#                           	struct Zone
#                              -------------------
#     début                : 9 mai 2023
#     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
#     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
# *************************************************************************/

//---------- Interface de la classe Zone (fichier Zone.h) ----------------

#ifndef Zone_H
#define Zone_H

//--------------------------------------------------- Interfaces utilisées
#include "Coordinates.h"

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <Zone>
// 
//------------------------------------------------------------------------

typedef struct{

    //---------------------------------------------------------- Attributs

    Coordinates center;
    float radius;

    bool isInside(Coordinates coordinates) {
        bool inside = false;
        if (coordinates.distanceTo(this.center) <= radius) inside = true;
        return inside;
    }

    float getDistanceFromCenter(Coordinates coordinates) {
        return coordinates.distanceTo(this.center);
    }

}Zone;

#endif