#include <iostream>
#include <fstream>
#include <list>
#include <typeinfo>
#include <ctime>
#include <string>
#include <assert.h>
#include <ctime>
using namespace std;


#include "../../src/System.h"
#include "../../src/Device.h"
#include "../../src/StatisticsServices.h"
#include "../../src/Measurement.h"
#include "../../src/Values.h"
#include "../../src/Conversions.h"

System s("../../../Databases/sensors_test.csv", "../../../Databases/cleaners_test.csv", "../../../Databases/users_test.csv", "../../../Databases/measurements_test.csv");

StatisticsServices ss;

//------------------------------------------ Déclarations méthodes de tests
void testGetAverageAirQualityZoneDate(string latitude, string longitude, string rad, string date);

void testGetAverageAirQualityMeasurements();

void testGetAverageAirQualityMeasurements(string v1_o3, string v1_no2, string v1_so2, string v1_pm10, string v2_o3, string v2_no2, string v2_so2, string v2_pm10);

//--------------------------------------------------- Définitions méthodes

template <typename T>
void printList(list<T*> lst) {  /*Méthode générique permettant d'afficher n'importe quelle liste à condition que << soit redéfini pour les objets de cette liste*/
    for (const auto& elem : lst) {
        cout << *elem << endl;
    }
    cout << endl;
}

int main(int argc, char * argv[]){

    assert(argc >= 2);

    string argument = argv[1];

    if (argument == "zoneDate") testGetAverageAirQualityZoneDate(argv[2], argv[3], argv[4], argv[5]);
    else if (argument == "measurements") {
        if (argc >= 10) testGetAverageAirQualityMeasurements(argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9]);
        else testGetAverageAirQualityMeasurements();
    } else {

    }


    return 0;
}


//------------------------------------------- Définitions méthodes de tests


void testGetAverageAirQualityMeasurements() {
    Values v = ss.getAverageAirQuality(s.getSensorsByName("Sensor1")->getMeasurements());
    cout << "Qualité de l'air moyen" << endl << "O3 : " << v.o3 << " ; NO2 : " <<  v.no2 << " ; SO2 : " <<  v.so2 << " ; PM10 : " <<  v.pm10 << endl;
}

void testGetAverageAirQualityMeasurements(string v1_o3, string v1_no2, string v1_so2, string v1_pm10, string v2_o3, string v2_no2, string v2_so2, string v2_pm10) {
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


void testGetAverageAirQualityZoneDate(string latitude, string longitude, string rad, string date) {

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
