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
#include <list>
#include <typeinfo>

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

// Méthode générique permettant d'afficher n'importe quelle liste à condition que << soit redéfini pour les objets de cette liste

template <typename T>
void printList(std::list<T> lst) {
    for (const auto& elem : lst) {
        std::cout << elem << endl;
    }
    std::cout << std::endl;
}


int main(int argc, char * argv[]){
  
    System s;


    /*Coordinates c;
    c.latitude=21;
    c.longitude=21;
    Sensor s = Sensor("sensor0",c);
    //Device  * d = *s;
    cout << s << endl;*/


    s.initializeSensors("../Databases/sensors.csv");

    cout << s.getSensors().size() << endl;

    cout << s.getSensors().front() << endl;


    // s.displayDevices();



    return 0;
}


//--------------------------------------------------- Définitions méthodes
