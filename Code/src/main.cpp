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

//------------------------------------------ Déclarations méthodes de tests
void testGetAverageAirQualityZoneDate(string latitude, string longitude, string rad, string date, StatisticsServices ss, System s);

void testGetAverageAirQualityMeasurements(string v1_o3, string v1_no2, string v1_so2, string v1_pm10, string v2_o3, string v2_no2, string v2_so2, string v2_pm10,  StatisticsServices ss);

template <typename T>
void printList(list<T*> lst) {  /*Méthode générique permettant d'afficher n'importe quelle liste à condition que << soit redéfini pour les objets de cette liste*/
    for (const auto& elem : lst) {
        cout << *elem << endl;
    }
    cout << endl;
}

int main(int argc, char * argv[]){

    string pause;
    StatisticsServices ss;
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
    cout << "Affichage de la liste des Sensors opérationnels après avoir blacklisté le sensor 100"<<endl;
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
    cout << "Affichage de la liste des Sensors opérationnels après avoir unblacklisté le sensor 100"<<endl;
    cout << "Saisissez un caractére pour continuer :";
    cin>>pause;
    cout <<endl;
    // On unblacklist le Sensor 100
    s.unBlacklistSensor(sensor);
    //Affichage des Sensors fonctionnels
    printList(s.getFunctionalSensors());
    cout <<endl;

    cout << "---------------------------------------------------------------------------"<<endl;
    cout << "Affichage de la liste des Sensors opérationnels après avoir blacklisté le sensor 15 (quelconque)"<<endl;
    cout << "Saisissez un caractére pour continuer :";
    cin>>pause;
    cout <<endl;
    // Récupération du Sensor15 puis ne le blackliste
    sensor = s.getSensorsByName("Sensor15");
    s.blacklistSensor(sensor);
    //Affichage des Sensors fonctionnels
    printList(s.getFunctionalSensors());
    cout <<endl;

    cout << "---------------------------------------------------------------------------"<<endl;
    cout << "Affichage de la liste des Sensors opérationnels après avoir unblacklisté le sensor 100"<<endl;
    cout << "Saisissez un caractére pour continuer :";
    cin>>pause;
    cout <<endl;
    // On unblacklist le Sensor 15
    s.unBlacklistSensor(sensor);
    //Affichage des Sensors fonctionnels
    printList(s.getFunctionalSensors());
    cout <<endl;

    cout << "---------------------------------------------------------------------------"<<endl;
    cout << "Affichage de la moyenne des mesures prises par le Sensor 1"<<endl;
    cout << "Saisissez un caractére pour continuer :";
    cin>>pause;
    cout <<endl;
    Values v = ss.getAverageAirQuality(s.getSensorsByName("Sensor1")->getMeasurements());
    cout << "Qualité de l'air moyen" << endl << "O3 : " << v.o3 << " ; NO2 : " <<  v.no2 << " ; SO2 : " <<  v.so2 << " ; PM10 : " <<  v.pm10 << endl; 
    cout <<endl;

    cout << "---------------------------------------------------------------------------"<<endl;
    cout << "Affichage de la moyenne des mesures prises dans la zone "<<endl;
    cout << "Saisissez un caractére pour continuer :";
    Coordinates coord;
    coord.latitude=44.4;
    coord.longitude=1.8;
    Zone z;
    z.center=coord;
    z.radius=1;
    string dateStr = "2019-03-01 00:00:00";
    ss.getAverageAirQuality(s.getFunctionalSensors(),z, (time_t) stringToTime_t(dateStr));
    cin>>pause;
    cout <<endl;


    return 0;
}


void testGetAverageAirQualityMeasurements(string v1_o3, string v1_no2, string v1_so2, string v1_pm10, string v2_o3, string v2_no2, string v2_so2, string v2_pm10, StatisticsServices ss) {
    Values v1;
    v1.create(stof(v1_o3), stof(v1_no2), stof(v1_so2), stof(v1_pm10));
    Values v2;
    v2.create(stof(v2_o3), stof(v2_no2), stof(v2_so2), stof(v2_pm10));
    string dateStr = "2019-03-01 00:00:00";
    Measurement* m1 = new Measurement(v1, (time_t) stringToTime_t(dateStr));
    Measurement* m2 = new Measurement(v2, (time_t) stringToTime_t(dateStr));
    list<Measurement*> measurements;
    measurements.push_back(m1);
    measurements.push_back(m2);
    Values v = ss.getAverageAirQuality(measurements);
    cout << "Qualité de l'air moyen" << endl << "O3 : " << v.o3 << " ; NO2 : " <<  v.no2 << " ; SO2 : " <<  v.so2 << " ; PM10 : " <<  v.pm10 << endl;
}


void testGetAverageAirQualityZoneDate(string latitude, string longitude, string rad, string date, StatisticsServices ss, System s) {

    Coordinates coord;
    coord.latitude = stof(latitude);
    coord.longitude = stof(longitude);
    float radius = stof(rad);

    Zone z;
    z.center = coord;
    z.radius = radius;

    string dateStr = date;

    Values v = ss.getAverageAirQuality(s.getFunctionalSensors(), z, stringToTime_t(dateStr));

    cout << "Qualité de l'air moyen" << endl << "O3 : " << v.o3 << " ; NO2 : " <<  v.no2 << " ; SO2 : " <<  v.so2 << " ; PM10 : " <<  v.pm10 << endl;
}

