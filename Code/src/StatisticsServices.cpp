#include <iostream>
using namespace std;

#include "StatisticsServices.h"
#include "Device.h"

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

// TODO: A MODIFIER
Values getAverageAirQuality(Measurement measurements[]){
  float avgO3 = 0, avgNO2 = 0,	avgSO2 = 0,	avgPM10 = 0;
  int nO3 = 0, nNO2 = 0,    nSO2 = 0,	nPM10 = 0;
  Values moyenne;

  return moyenne;
}
