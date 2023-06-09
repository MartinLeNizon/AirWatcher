#if ! defined ( Sensor_H )
#define Sensor_H

#include "Device.h"
#include "PrivateUser.h"
#include "Measurement.h"

#include <string>
#include <list>
#include <ctime>

class PrivateUser;

class Sensor : public Device {

public:

//-------------------------------------------- Constructeurs - destructeur

    Sensor(const Sensor & unSensor);

    Sensor(string nom, Coordinates pos);

    Sensor();

    virtual ~Sensor();

//------------------------------------------------- Surcharge d'opérateurs
    Sensor & operator = ( const Sensor & unSensor );


    friend istream & operator >> (istream & is, Sensor &d);

    friend ostream & operator << (ostream & os, const Sensor &s);

//-------------------------------------------------------- Autres méthodes

    string getName() const;

    bool getBlacklisted() const;

    void setBlacklisted(bool blacklist);

    void setBlacklistedSensor(bool blacklist);

    PrivateUser* getPrivateUser() const;

    void setPrivateUser(PrivateUser* monUser);   // Permet de setter le privateUser d'un sensor

    list<Measurement*> getMeasurements();

    list<Measurement*> getMeasurements(time_t date);

    void addMeasurement (Measurement* m);

    bool operator==(const Sensor* s) const;
    bool operator==(const Sensor& s) const;


protected:
    bool blacklisted;
    PrivateUser* privateUser;
    list<Measurement*> measurements;
};

#endif

