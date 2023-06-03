/*************************************************************************
                          		        main
                              -------------------
     début                : 9 mai 2023
     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
*************************************************************************/

// TODO: Rajouter traces de debug

using namespace std;
#include <iostream>
#include <fstream>
#include <list>
#include <typeinfo>
#include <ctime>

#include "../../src/System.h"
#include "../../src/Device.h"
#include "../../src/Sensor.h"
#include "../../src/Cleaner.h"
#include "../../src/Measurement.h"
#include "../../src/Values.h"
#include "../../src/Coordinates.h"
#include "../../src/Zone.h"
#include "../../src/Conversions.h"
#include "../../src/PrivateUser.h"

template <typename T>
void printList(list<T*> lst) {  /*Méthode générique permettant d'afficher n'importe quelle liste à condition que << soit redéfini pour les objets de cette liste*/
    for (const auto& elem : lst) {
        cout << *elem << endl;
    }
    cout << endl;
}

int main(int argc, char * argv[]){

    System s("../../Databases/sensors.csv", "../../Databases/cleaners.csv", "../../Databases/users.csv", "../../Databases/measurements.csv");

    if(argv[1]=="AffichageSensors"){

        //Affichage de la liste des Sensors
        printList(s.getSensors());

    } else if (argv[1]=="AffichageDevices"){
        
        //Affichage de la liste des Devices
        printList(s.getDevices());

    } else if (argv[1]=="AffichagePrivateUsers"){
        
        //Affichage de la liste des privates users Devices
        printList(s.getPrivateUsers());

    } else if (argv[1]=="BlacklistSensor100"){

        // Récupération du Sensor100 puis ne le blackliste
        Sensor* sensor = s.getSensorsByName("Sensor100");
        s.blacklistSensor(sensor);

        //Affichage des Sensors fonctionnels
        printList(s.getFunctionalSensors());

    } else if (argv[1]=="UnBlacklistSensor100"){

        // Récupération du Sensor100 puis ne le blackliste
        Sensor* sensor = s.getSensorsByName("Sensor100");
        s.blacklistSensor(sensor);

        // On unblackliste le Sensor100
        s.unBlacklistSensor(sensor);

        //Affichage des Sensors fonctionnels
        printList(s.getFunctionalSensors());

    }

        

    return 0;
}


//--------------------------------------------------- Définitions méthodes


//--------------------------------------------------- Méthodes de tests
