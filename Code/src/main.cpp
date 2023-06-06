/*************************************************************************
                          		        main
                              -------------------
     début                : 9 mai 2023
     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
*************************************************************************/

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

    string pause;
    System s("../Databases/sensors.csv", "../Databases/cleaners.csv", "../Databases/users.csv", "../Databases/measurements.csv");

    cout << "Affichage de la liste des Devices"<<endl;
    printList(s.getDevices());

    cout <<endl;
    
    
    cout << "---------------------------------------------------------------------------"<<endl;
    cout << "Affichage de la liste des PrivateUsers"<<endl;
    cout << "Saisissez un caractére pour continuer :";
    cin>>pause;
    cout <<endl;
    printList(s.getPrivateUsers());
    cout <<endl;

    cout << "---------------------------------------------------------------------------"<<endl;
    cout << "Affichage de la liste des Cleaners"<<endl;
    cout << "Saisissez un caractére pour continuer :";
    cin>>pause;
    cout <<endl;
    printList(s.getCleaners());
    cout <<endl;

    cout << "---------------------------------------------------------------------------"<<endl;
    cout << "Affichage de la liste des Sensors"<<endl;
    cout << "Saisissez un caractére pour continuer :";
    cin>>pause;
    cout <<endl;
    printList(s.getFunctionalSensors());
    cout <<endl;

    cout << "---------------------------------------------------------------------------"<<endl;
    cout << "Affichage de la liste des Sensors oprérationnels après avoir blacklisté le sensor 100"<<endl;
    cout << "Saisissez un caractére pour continuer :";
    cin>>pause;
    cout <<endl;
    // Récupération du Sensor1 puis ne le blackliste
    Sensor* sensor = s.getSensorsByName("Sensor100");
    s.blacklistSensor(sensor);
    //Affichage des Sensors fonctionnels
    printList(s.getFunctionalSensors());
    cout <<endl;

    cout << "---------------------------------------------------------------------------"<<endl;
    cout << "Affichage de la liste des Sensors oprérationnels après avoir unblacklisté le sensor 100"<<endl;
    cout << "Saisissez un caractére pour continuer :";
    cin>>pause;
    cout <<endl;
    // On unblacklist le Sensor 100
    s.unBlacklistSensor(sensor);
    //Affichage des Sensors fonctionnels
    printList(s.getFunctionalSensors());
    cout <<endl;

    cout << "---------------------------------------------------------------------------"<<endl;
    cout << "Affichage de la liste des Sensors oprérationnels après avoir blacklisté le sensor 15 (quelconque)"<<endl;
    cout << "Saisissez un caractére pour continuer :";
    cin>>pause;
    cout <<endl;
    // Récupération du Sensor1 puis ne le blackliste
    sensor = s.getSensorsByName("Sensor15");
    s.blacklistSensor(sensor);
    //Affichage des Sensors fonctionnels
    printList(s.getFunctionalSensors());
    cout <<endl;

    cout << "---------------------------------------------------------------------------"<<endl;
    cout << "Affichage de la liste des Sensors oprérationnels après avoir unblacklisté le sensor 100"<<endl;
    cout << "Saisissez un caractére pour continuer :";
    cin>>pause;
    cout <<endl;
    // On unblacklist le Sensor 100
    s.unBlacklistSensor(sensor);
    //Affichage des Sensors fonctionnels
    printList(s.getFunctionalSensors());
    cout <<endl;


    return 0;
}
