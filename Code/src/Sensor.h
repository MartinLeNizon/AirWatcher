#if ! defined ( Sensor_H )
#define Sensor_H

#include "Device.h"
#include "PrivateUser.h"
#include "Measurement.h"

#include <string>
#include <list>

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

    void setPrivateUser(PrivateUser* monUser);   // Permet de setter l'user d'un sensor

    list<Measurement*> getMeasurements();

    void addMeasurement (Measurement* m);


protected:
    bool blacklisted;
    PrivateUser* user;
    list<Measurement*> measurements;
};

#endif

