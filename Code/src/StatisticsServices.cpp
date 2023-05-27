#include <iostream>
#include <iterator>
using namespace std;

#include "StatisticsServices.h"
#include "Device.h"
#include "Values.h"

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

Values StatisticsServices::getAverageAirQuality(Measurement measurements[], int size){
    float avgO3 = 0, avgNO2 = 0, avgSO2 = 0, avgPM10 = 0;
    int nO3 = 0, nNO2 = 0, nSO2 = 0, nPM10 = 0;
        for (int i=0; i<size; i++) {
        if (measurements[i].getValues().o3 != 0) {
            nO3++;
            avgO3 += measurements[i].getValues().o3;
        }
        if (measurements[i].getValues().no2 != 0) {
            nNO2++;
            avgNO2 += measurements[i].getValues().no2;
        }
        if (measurements[i].getValues().so2 != 0) {
            nSO2++;
            avgSO2 += measurements[i].getValues().so2;
        }
        if (measurements[i].getValues().pm10 != 0) {
            nPM10++;
            avgPM10 += measurements[i].getValues().pm10;
        }
    }

    avgO3 /= nO3;
    avgNO2 /= nNO2;
    avgSO2 /= nSO2;
    avgPM10 /= nPM10;

    Values moyenne;
    moyenne.o3 = avgO3;
    moyenne.no2 = avgNO2;
    moyenne.so2 = avgSO2;
    moyenne.pm10 = avgPM10;

    return moyenne;
}
