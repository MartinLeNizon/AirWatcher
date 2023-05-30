#if ! defined ( StatisticsServices_H )
#define StatisticsServices_H

#include "Coordinates.h"
#include "Measurement.h"
#include "Values.h"
#include "Zone.h"
#include "Sensor.h"

class StatisticsServices {

public:

//-------------------------------------------- Constructeurs - destructeur
    StatisticsServices(const StatisticsServices & unStatisticsServices);

    StatisticsServices();

    virtual ~StatisticsServices();

//------------------------------------------------- Surcharge d'opérateurs
    StatisticsServices & operator = ( const StatisticsServices & unStatisticsServices );

//-------------------------------------------------------- Autres méthodes
    Values getAverageAirQuality(list<Sensor*> sensors, Zone zone, time_t date);
    

protected:

    Coordinates position;

    Values getAverageAirQuality(list<Measurement*> measurements);


};

#endif
