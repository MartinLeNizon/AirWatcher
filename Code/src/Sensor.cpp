#include <iostream>
using namespace std;

#include "Sensor.h"
#include "Device.h"

//-------------------------------------------- Constructeurs - destructeur

Sensor::Sensor(const Sensor & unSensor) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
}

Sensor::Sensor() {
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif

    blacklisted = false;
}

Sensor::Sensor (string nom, Coordinates pos) : Device(nom,pos) {
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif

    blacklisted = false;
    user = NULL;
}

Sensor::~Sensor() {
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif
}


//------------------------------------------------- Surcharge d'opérateurs

istream & operator >> (istream & is, Sensor & s){
    string res1="";
    string res2="";
    string res3="";
    getline(is,res1,';');
    getline(is,res2,';');
    getline(is,res3,';');

    if (res1!="" && res2!="" && res3!=""){
        s.name = res1;
        s.position.longitude=stof(res2);
        s.position.latitude=stof(res3);
    }

    return is;
}

ostream & operator << (ostream & os, const Sensor &s){
    string status ="Operational";
    if(s.blacklisted==true){
        status = "Blacklisted";
    }
    os << s.name << ";" << s.position.longitude << ";" << s.position.latitude << ";" << status << ";";
    return os;
}

//-------------------------------------------------------- Autres méthodes

string Sensor::getName() const {
    return name;

}

bool Sensor::getBlacklisted() const {
    return blacklisted;
}

void Sensor::setBlacklisted(bool blacklist) {   // Permet de blacklister ou d'unblacklister un sensor
    blacklisted = blacklist;

}

void Sensor::setBlacklistedSensor(bool blacklist) { // Permet de blacklister ou d'unblacklister un sensor et tous les sensors associées de l'user
    blacklisted = blacklist;

    if (blacklisted && user != NULL) {
        user->setBlacklistedUser(true);
    }
}

PrivateUser* Sensor::getPrivateUser() const {   // Permet d'accéder à l'attribut user du sensor
    return user;
}

void Sensor::setPrivateUser(PrivateUser* monUser) {    // Algorithme : Permet de set l'user d'un sensor
    user = monUser;
}

// TODO: Mettre getMeasurements
list<Measurement*> Sensor::getMeasurement() {
    return measurements;
}

void Sensor :: addMeasurement(Measurement* m) {
    measurements.push_back(m);
}
