#if ! defined ( Measurement_H )
#define Measurement_H

#include <time.h>
#include "Values.h"

class Measurement {

public:

//-------------------------------------------- Constructeurs - destructeur

    Measurement( const Measurement & unMeasurement );

    Measurement(Values value, time_t dateMesure);

    virtual ~Measurement();


//------------------------------------------------- Surcharge d'opérateurs
    Measurement & operator = ( const Measurement & unMeasurement );

    friend istream & operator >> (istream & is, Measurement &c);

    friend ostream & operator << (ostream & os, const Measurement &c);

    Measurement ( );

protected:
    Values value;
    time_t date;

};

#endif

