#include <iostream>
#include <iterator>
#include <list>
#include <ctime>
#ifdef PERF
    #include <chrono>
#endif
using namespace std;

#include "StatisticsServices.h"
#include "Device.h"
#include "Values.h"
#include "Measurement.h"
#include "Coordinates.h"
#include "Zone.h"


//-------------------------------------------- Constructeurs - destructeur
StatisticsServices::StatisticsServices(const StatisticsServices & unStatisticsServices) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <StatisticsServices>" << endl;
#endif
}


StatisticsServices::StatisticsServices() {
#ifdef MAP
    cout << "Appel au constructeur de <StatisticsServices>" << endl;
#endif
}


StatisticsServices::~StatisticsServices() {
#ifdef MAP
    cout << "Appel au destructeur de <StatisticsServices>" << endl;
#endif
}


Values StatisticsServices::getAverageAirQuality(list<Sensor*> sensors, Zone zone, time_t date) {
#ifdef MAP
    cout << "Appel a <StatisticsServices::getAverageAirQuality>" << endl;
#endif

    #ifdef PERF
        auto start = chrono::high_resolution_clock::now();
    #endif

    if (zone.radius < 0) {
        zone.radius *= -1;
        cerr << "Le rayon de la zone doit être positif : prise en compte de sa valeur absolue" << endl;
    }

    list<Measurement*> measurements;

    for (const auto& s : sensors) {
        #ifdef MAP
            cout << "Latitude  : " << s->getPosition().latitude << endl;
            cout << "Longitude : " << s->getPosition().longitude << endl;
        #endif
        if ( zone.isInside(s->getPosition()) ) {
            #ifdef MAP
                cout << "Inside the zone : " << *s << endl << endl;
            #endif

            for (const auto& m : s->getMeasurements()) {

                time_t date1 = m->getDate();

                struct tm* timeinfo1 = gmtime(&date1);
                struct tm* timeinfo2 = gmtime(&date);

                int day1 = timeinfo1->tm_mday;
                int month1 = timeinfo1->tm_mon + 1;
                int year1 = timeinfo1->tm_year + 1900;

                int day2 = timeinfo2->tm_mday;
                int month2 = timeinfo2->tm_mon + 1;
                int year2 = timeinfo2->tm_year + 1900;

                if (day1 == day2 && month1 == month2 && year1 == year2) {
                    #ifdef MAP
                        cout << "Measurements taken into account : " << endl << *m;
                    #endif

                    measurements.push_back(m);
                    if (s->getPrivateUser() != NULL) {
                        s->getPrivateUser()->addPoint();

                        #ifdef MAP
                            cout << "The sensor of this measure have a private user : " << endl << *s->getPrivateUser() << endl << endl;
                        #endif
                    } else {
                        #ifdef MAP
                            cout << "The sensor of this measure doesn't have a private user" << endl << endl;
                        #endif
                    }
                }
            }
        } else {
            #ifdef MAP
                cout << "Outside the zone : " << *s << endl << endl;
            #endif
        }
    }

    if (measurements.empty()) {
        #ifdef MAP
            cout << "No measurement in this zone at that date" << endl;
        #endif
    }

    #ifdef PERF
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Temps d'exécution getAverageAirQuality(list<Sensor*> sensors, Zone zone, time_t date) : " << duration.count() << " ms" << endl;
    #endif

    return getAverageAirQuality(measurements);
}


Values StatisticsServices::getAverageAirQuality(list<Measurement*> measurements){
    float avgO3 = 0, avgNO2 = 0, avgSO2 = 0, avgPM10 = 0;
    int nO3 = 0, nNO2 = 0, nSO2 = 0, nPM10 = 0;

    for (const auto& m : measurements) {
        if (m->getValues().o3 >= 0) {
            nO3++;
            avgO3 += m->getValues().o3;
        } else cerr << "Valeur en O3 non prise en compte : doit être positive" << endl;
        if (m->getValues().no2 >= 0) {
            nNO2++;
            avgNO2 += m->getValues().no2;
        } else cerr << "Valeur en NO2 non prise en compte : doit être positive" << endl;
        if (m->getValues().so2 >= 0) {
            nSO2++;
            avgSO2 += m->getValues().so2;
        } else cerr << "Valeur en SO2 non prise en compte : doit être positive" << endl;
        if (m->getValues().pm10 >= 0) {
            nPM10++;
            avgPM10 += m->getValues().pm10;
        } else cerr << "Valeur en PM10 non prise en compte : doit être positive" << endl;
    }

    if (nO3 != 0) avgO3 /= nO3;
    if (nNO2 != 0) avgNO2 /= nNO2;
    if (nSO2 != 0) avgSO2 /= nSO2;
    if (nPM10 != 0) avgPM10 /= nPM10;

    Values moyenne;
    moyenne.o3 = avgO3;
    moyenne.no2 = avgNO2;
    moyenne.so2 = avgSO2;
    moyenne.pm10 = avgPM10;

    return moyenne;
}
