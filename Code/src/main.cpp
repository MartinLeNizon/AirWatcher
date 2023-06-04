/*************************************************************************
                          		        main
                              -------------------
     début                : 9 mai 2023
     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
*************************************************************************/

// TODO:
// Rajouter traces de debug
// Changer chemin d'accès aux fichiers (pour que ça marche de partout)
// StatisticsServices Comparaison des dates non fonctionnelle
// Réorganiser le main & mettre les tests dans des méthodes séparées
// Lire les lignes des measurements.csv par 4

using namespace std;
#include <iostream>
#include <fstream>
#include <list>
#include <typeinfo>
#include <ctime>

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
#include "StatisticsServices.h"
#include "Conversions.h"

template <typename T>
void printList(list<T*> lst) {  /*Méthode générique permettant d'afficher n'importe quelle liste à condition que << soit redéfini pour les objets de cette liste*/
    for (const auto& elem : lst) {
        cout << *elem << endl;
    }
    cout << endl;
}

int main(int argc, char * argv[]){
  
    //System s("../Databases/sensors.csv", "../Databases/cleaners.csv", "../Databases/users.csv", "../Databases/measurements.csv");

    //printList(s.getSensors().front()->getMeasurements());

    /*//Affichage de la liste des Sensors
    printList(s.getSensors());
    
    //Affichage de la liste des Cleaners
    printList(s.getCleaners());

    //Affichage de la liste des PrivateUsers
    printList(s.getPrivateUsers());

    //Blacklist le Sensor100 et vérification
    Sensor* sensor = s.getSensorsByName("Sensor100");
    //cout<<(*sensor)<<endl;
    s.blacklistSensor(sensor);

    //unBlacklist le sensor100 et vérification (le sensor70 réapparaît normalement)
    s.unBlacklistSensor(sensor);
    printList(s.getFunctionalSensors());

    printList(s.getFunctionalSensors());

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

    printList(s.getFunctionalSensors());*/


    // System s("../Databases/sensors.csv", "../Databases/cleaners.csv", "../Databases/users.csv", "../Databases/measurements.csv");

    System s("../Databases/sensors_test.csv", "../Databases/cleaners_test.csv", "../Databases/users_test.csv", "../Databases/measurements_test.csv");

    StatisticsServices ss;

    printList(s.getSensors().front()->getMeasurements());

    // Tests déplacés dans le framework

    return 0;
}
