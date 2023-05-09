# /*************************************************************************
#                           	struct Values
#                              -------------------
#     début                : 9 mai 2023
#     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
#     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
# *************************************************************************/

//---------- Interface de la classe Values (fichier Values.h) ----------------

#ifndef Values_H
#define Values_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <iostream>

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <Values>
// 
//------------------------------------------------------------------------

typedef struct{

    //---------------------------------------------------------- Attributs

    float o2;
    float no2;
    float so2;
    float pm10;

}Values;

#endif