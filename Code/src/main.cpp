# /*************************************************************************
#                           		        main
#                              -------------------
#     début                : 9 mai 2023
#     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
#     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
# *************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "System.h"
#include "Device.h"
#include "Sensor.h"
#include "Cleaner.h"
#include "Measurement.h"
#include "Values.h"
#include "Coordinates.h"
#include "Zone.h"

//------------------------------------------------------------------ Types

//------------------------------------------------------------- Constantes

//-------------------------------------------------- Déclarations méthodes

//------------------------------------------------------------------- main
int main(int argc, char * argv[]){
  
  System s;
  s.initializeSensors("../../Databases/sensors.csv");

  std::ifstream infile("../../Databases/sensors.csv");

    if (!infile) {
        std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
        return 1;
    }



  return 0;
}


//--------------------------------------------------- Définitions méthodes
