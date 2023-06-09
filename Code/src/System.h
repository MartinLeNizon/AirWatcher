#if ! defined ( System_H )
#define System_H

#include <list>
#include <string>

#include "Device.h"
#include "Sensor.h"
#include "User.h"
#include "Provider.h"
#include "PrivateUser.h"

class System {

public:


//-------------------------------------------- Constructeurs - destructeur
    System(const System & unSystem);

    System(const string ficSensors, const string ficCleaners, const string ficPrivateUsers, const string ficMeasurements);

    virtual ~System();

//------------------------------------------------- Surcharge d'opérateurs

    System & operator = (const System & unSystem);

//-------------------------------------------------------- Autres méthodes

    list<Device*> getDevices() const;

    list<Sensor*> getSensors() const;

    list<Cleaner*> getCleaners() const;

    list<PrivateUser*> getPrivateUsers()const;

    //int addSensorToPrivateUser(string name, string sensorName);

    int addSensorToPrivateUser(string name, Sensor* monSensor);

    list<Sensor*> getFunctionalSensors() const;

    Sensor* getSensorsByName(string n);

    void blacklistSensor(Sensor* s);
    void unBlacklistSensor(Sensor* s);

    /*void displaySensors() const;*/

protected:
    list<Device*> devices;
    list<User*> users;
    list<Provider*> providers;
    list<Sensor*> blacklistedSensors;

    void initializeSensors(const string nomFic);

    void initializeCleaners(const string nomFic);

    void initializePrivateUsers(const string nomFic);

    void initializeMeasurements(const string fileName);
};


#endif
