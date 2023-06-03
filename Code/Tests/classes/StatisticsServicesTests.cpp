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
#include <string>

#include "../../src/System.h"
#include "../../src/Device.h"
#include "../../src/StatisticsServices.h"
#include "../../src/Measurement.h"
#include "../../src/Values.h"
#include "../../src/Conversions.h"

template <typename T>
void printList(list<T*> lst) {  /*Méthode générique permettant d'afficher n'importe quelle liste à condition que << soit redéfini pour les objets de cette liste*/
    for (const auto& elem : lst) {
        cout << *elem << endl;
    }
    cout << endl;
}

int main(int argc, char * argv[]){

    System s("../../../Databases/sensors_test.csv", "../../../Databases/cleaners_test.csv", "../../../Databases/users_test.csv", "../../../Databases/measurements_test.csv");

    StatisticsServices ss;

    string argument = argv[1];

    if(argument == "AverageAirQuality"){
        
        Values v1;
        v1.create(50.25, 74.5, 41.5, 44.75);
        Values v2;
        v2.create(50.5, 72, 39.25, 50.5);

        string dateStr = "2019-03-01 00:00:00";

        Measurement* m1 = new Measurement(v1, (time_t) stringToTime_t(dateStr));
        Measurement* m2 = new Measurement(v2, (time_t) stringToTime_t(dateStr));

        list<Measurement*> measurements;
        measurements.push_back(m1);
        measurements.push_back(m2);

        Values v = ss.getAverageAirQuality(measurements);
        cout << "Qualité de l'air moyen" << endl << "O3 : " << v.o3 << " ; NO2 : " <<  v.no2 << " ; SO2 : " <<  v.so2 << " ; PM10 : " <<  v.pm10 << endl;
        
    } else if (argument =="AverageAirQualityZoneDate"){
        
        Coordinates coord;
        coord.latitude = 45;
        coord.longitude = 1;
        float radius = 1;

        Zone z;
        z.center = coord;
        z.radius = radius;

        string dateStr = "2019-01-03 12:00:00";

        Values v = ss.getAverageAirQuality(s.getFunctionalSensors(), z, stringToTime_t(dateStr));
        cout << "Qualité de l'air moyen" << endl << "O3 : " << v.o3 << " ; NO2 : " <<  v.no2 << " ; SO2 : " <<  v.so2 << " ; PM10 : " <<  v.pm10 << endl;
        
    }

        

    return 0;
}


//--------------------------------------------------- Définitions méthodes


//--------------------------------------------------- Méthodes de tests