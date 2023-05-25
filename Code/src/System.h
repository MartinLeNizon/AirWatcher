#if ! defined ( System_H )
#define System_H

#include "Device.h"
#include "Sensor.h"
#include "User.h"
#include "Provider.h"
#include "PrivateUser.h"
#include <list>
#include <string>

class System {

public:


//-------------------------------------------- Constructeurs - destructeur
    System(const System & unSystem);

    System();

    virtual ~System();

//------------------------------------------------- Surcharge d'opérateurs

    System & operator = (const System & unSystem);

//-------------------------------------------------------- Autres méthodes

    void initializeSensors(const string nomFic);

    list<Device*> getDevices() const;

    list<Sensor*> getSensors() const;

    list<Cleaner*> getCleaners() const;

    list<PrivateUser*> getPrivateUsers()const;

    void initializeCleaners(const string nomFic);

    void initializePrivateUsers(const string nomFic);

    //int addSensorToPrivateUser(string name, string sensorName);

    int addSensorToPrivateUser(string name, Sensor* monSensor);

    list<Sensor*> getFunctionalSensors() const;

    void initializeMeasurements(const string fileName);

    /*void displaySensors() const;*/

protected:
  list<Device*> devices;
  list<User*> users;
  list<Provider*> providers;
};


#endif
