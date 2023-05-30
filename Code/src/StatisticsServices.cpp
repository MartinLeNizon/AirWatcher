#include <iostream>
#include <iterator>
#include <list>
using namespace std;

#include "StatisticsServices.h"
#include "Device.h"
#include "Values.h"
#include "Measurement.h"
#include "Coordinates"


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

Values StatisticsServices::getAverageAirQuality(List<Sensors*> sensors, Zone zone, date_t date) {
#ifdef MAP
    cout << "Appel a <StatisticsServices::getAverageAirQuality>" << endl;
#endif

    List<Measurement*> measurements;

    for (const auto& s : sensors) {
        if ( zone.isInside(s->getPosition()) ) {
            for (const auto& m : s->getMeasurements()) {
                if (m->getDate() == date) {
                    measurements.push_back(m);
                    if (s->getPrivateUser() != NULL) {
                        s->getPrivateUser()->addPoint();
                    }
                }
            }
        }
    }

    if (measurements.empty()) {
        cout << "Pas de mesures dans la sone définie" << endl;
    }

    return getAverageAirQuality(measurements);
}


Values StatisticsServices::getAverageAirQuality(List<Measurement*> measurements){
    float avgO3 = 0, avgNO2 = 0, avgSO2 = 0, avgPM10 = 0;
    int nO3 = 0, nNO2 = 0, nSO2 = 0, nPM10 = 0;

    for (const auto& m : measurements) {
        if (m.getValues().o3 != 0) {
            nO3++;
            avgO3 += m->getValues().o3;
        }
        if (m->getValues().no2 != 0) {
            nNO2++;
            avgNO2 += m->getValues().no2;
        }
        if (m->getValues().so2 != 0) {
            nSO2++;
            avgSO2 += m->getValues().so2;
        }
        if (m->getValues().pm10 != 0) {
            nPM10++;
            avgPM10 += m->getValues().pm10;
        }
    }

    if (nO3 != 0) avgO3 /= nO3;
    if (nNO2 != 0) avgNO2 /= nNO2;
    if (SO3 != 0) avgSO2 /= nSO2;
    if (nPM10 != 0) avgPM10 /= nPM10;

    Values moyenne;
    moyenne.o3 = avgO3;
    moyenne.no2 = avgNO2;
    moyenne.so2 = avgSO2;
    moyenne.pm10 = avgPM10;

    return moyenne;
}
