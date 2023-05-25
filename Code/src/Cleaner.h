
#if ! defined ( Cleaner_H )
#define Cleaner_H

#include "Device.h"
#include "Coordinates.h"

#include <time.h>

class Cleaner : public Device {

public:

    Cleaner & operator = ( const Cleaner & unCleaner );


//-------------------------------------------- Constructeurs - destructeur

    Cleaner(const Cleaner & unCleaner);

    Cleaner(string nom, Coordinates pos, time_t start, time_t stop);


    Cleaner();

    virtual ~Cleaner();


//------------------------------------------------- Surcharge d'opérateurs

    friend istream & operator >> (istream & is, Cleaner &c);

    friend ostream & operator << (ostream & os, const Cleaner &c);

    bool operator == (const Cleaner& c) const;

protected:

    time_t startTime;
    time_t stopTime;

};

#endif

