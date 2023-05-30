#if ! defined ( StatisticsServices_H )
#define StatisticsServices_H

#include "Coordinates.h"
#include "Measurement.h"
#include "Values.h"

class StatisticsServices {

public:

//-------------------------------------------- Constructeurs - destructeur
    StatisticsServices(const StatisticsServices & unStatisticsServices);

    StatisticsServices();

    virtual ~StatisticsServices();

//------------------------------------------------- Surcharge d'opérateurs
    StatisticsServices & operator = ( const StatisticsServices & unStatisticsServices );

//-------------------------------------------------------- Autres méthodes
    Values getAverageAirQuality(List<Sensors> sensors, Zone zone, date_t date);
    

protected:

    Coordinates position;

    Values getAverageAirQuality(Measurement measurements[], int size);


};

#endif
