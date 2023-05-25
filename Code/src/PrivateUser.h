#if ! defined ( PrivateUser_H )
#define PrivateUser_H

#include <string.h>
#include <list>

#include "User.h"
#include "Sensor.h"

class PrivateUser : public User {

public:

//-------------------------------------------- Constructeurs - destructeur
    PrivateUser(const PrivateUser & unPrivateUser);

    PrivateUser();

    PrivateUser(string nom, Sensor* monSensor);

    PrivateUser(string nom, long point, Sensor* monSensor);

    virtual ~PrivateUser();

//------------------------------------------------- Surcharge d'opérateurs

    PrivateUser & operator = (const PrivateUser & unPrivateUser);

    friend ostream & operator << (ostream & os, const PrivateUser &u);

//-------------------------------------------------------- Autres méthodes

    string getSensorsName() const ;

    void addSensor(Sensor* s);

    list<Sensor*> getSensors() const;

    bool getBlacklisted() const;

    void setBlacklistedUser(bool blacklist);

protected:
  bool blacklisted;
  long points;
  list<Sensor*> sensors;
};

#endif
