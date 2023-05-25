#include <iostream>
#include <string>
using namespace std;

#include "PrivateUser.h"

//-------------------------------------------- Constructeurs - destructeur

PrivateUser::PrivateUser(const PrivateUser & unPrivateUser) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <PrivateUser>" << endl;
#endif
    name=unPrivateUser.name;
    surname=unPrivateUser.surname;
    mail=unPrivateUser.mail;
    password=unPrivateUser.password;
    blacklisted=unPrivateUser.blacklisted;
    points=unPrivateUser.points;

}


PrivateUser::PrivateUser() {
#ifdef MAP
    cout << "Appel au constructeur de <PrivateUser>" << endl;
#endif
}

PrivateUser :: PrivateUser(string name, Sensor* monSensor) : User(name) {
    addSensor(monSensor);
    points=0;
    blacklisted=0;
}

PrivateUser::PrivateUser(string nom, long point, Sensor* monSensor) : User(nom) {
#ifdef MAP
    cout << "Appel au constructeur de <PrivateUser>" << endl;
#endif

    points=point;
    addSensor(monSensor);
}

PrivateUser::~PrivateUser() {
#ifdef MAP
    cout << "Appel au destructeur de <PrivateUser>" << endl;
#endif
}

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator << (ostream & os, const PrivateUser &u) {
    os << u.name << "; blacklisted : "<<u.blacklisted<<"; points : "<< u.points <<";Sensors :"<<u.getSensorsName();
    return os;
}

//-------------------------------------------------------- Autres méthodes

string PrivateUser :: getSensorsName() const {
    string listeSensors="";
    int nbSensor=0;
    
    for (const auto& elem : sensors) {
        if(nbSensor!=0){
            listeSensors+="|";
        }
        listeSensors+=elem->getName();
        nbSensor++;
    }

    return listeSensors;
}

list<Sensor*> PrivateUser::getSensors() const {
    return sensors;
}

void PrivateUser :: addSensor(Sensor* s){
    sensors.push_back(s);
}

bool PrivateUser::getBlacklisted() const {
    return blacklisted;
}

void PrivateUser::setBlacklistedUser(bool blacklist) {
// Permet de blacklister ou d'unblacklister un user
    blacklisted = blacklist;

    if (blacklist) {
        for (const auto & sensor : sensors) {
            sensor->setBlacklisted(true);
        }
    }
}