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
#include <ctime>

//------------------------------------------------------ Include personnel
#include "System.h"
#include "Device.h"
#include "Sensor.h"
#include "Cleaner.h"
#include "Measurement.h"
#include "Values.h"
#include "Coordinates.h"
#include "Zone.h"
#include "Conversions.h"
#include "PrivateUser.h"

//------------------------------------------------------------------ Types

//------------------------------------------------------------- Constantes

//-------------------------------------------------- Déclarations méthodes

//------------------------------------------------------------------- main


/*Méthode générique permettant d'afficher n'importe quelle liste à condition que << soit redéfini pour les objets de cette liste*/

template <typename T>
void printList(list<T*> lst) {
    for (const auto& elem : lst) {
        cout << *elem << endl;
    }
    cout << endl;
}


int main(int argc, char * argv[]){
  
    System s;

    //Initialisation des Sensors
    s.initializeSensors("../../Databases/sensors.csv");

    //Initialisation des Cleaners
    s.initializeCleaners("../../Databases/cleaners.csv");

    //Initialisation des PrivateUsers
    s.initializePrivateUsers("../../Databases/users.csv");

    //Affichage de la liste des Sensors
    printList(s.getSensors());

    //Affichage de la liste des Cleaners
    printList(s.getCleaners());

    //Affichage de la liste des PrivateUsers
    printList(s.getPrivateUsers());

    //Test des fonctions de convertions
    string dateStr = "2019-03-01 00:00:00";
    time_t time=stringToTime_t(dateStr);
    std::cout << "Date et heure : " << time_tToString(time) << std::endl;

    //Test blacklist des sensors

    Sensor* s1 = s.getSensors().front();
    Sensor* s2 = s.getSensors().back();

    s.addSensorToPrivateUser("User0", s1);
    s.addSensorToPrivateUser("User1", s2);

    s.getPrivateUsers().front()->setBlacklistedUser(true);
    s.getSensors().back()->setBlacklistedSensor(true);
    
    PrivateUser* user = s.getPrivateUsers().front();
    cout << *user << endl;
    printList(user->getSensors());

    PrivateUser* user2 = s.getPrivateUsers().back();
    cout << *user2 << endl;
    printList(user2->getSensors());

    cout << endl; 

    printList(s.getFunctionalSensors());

    
    
    



    return 0;
}


//--------------------------------------------------- Définitions méthodes
