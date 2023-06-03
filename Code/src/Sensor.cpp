#include <iostream>
#include <ctime>
using namespace std;

#include "Sensor.h"
#include "Device.h"
#include "PrivateUser.h"

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
    privateUser = NULL;
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

void Sensor::setBlacklistedSensor(bool blacklist) { // Permet de blacklister ou d'unblacklister un sensor et tous les sensors associées de le privateUser
    blacklisted = blacklist;

    if (blacklisted && privateUser != NULL) {
        privateUser->setBlacklistedUser(true);
    }
}

PrivateUser* Sensor::getPrivateUser() const {   // Permet d'accéder à l'attribut privateUser du sensor
    return privateUser;
}


void Sensor::setPrivateUser(PrivateUser* monUser) {    // Algorithme : Permet de set l'user d'un sensor
    privateUser = monUser;
}

list<Measurement*> Sensor::getMeasurements() {
    return measurements;
}

list<Measurement*> Sensor::getMeasurements(time_t date) {

    list<Measurement*> selectedMeasurements;

    for (const auto& m : measurements) {

                time_t date1 = m->getDate();

                struct tm timeinfo1, timeinfo2;
                gmtime_s(&timeinfo1, &date1);
                gmtime_s(&timeinfo2, &date);

                int day1 = timeinfo1.tm_mday;
                int month1 = timeinfo1.tm_mon + 1;
                int year1 = timeinfo1.tm_year + 1900;

                int day2 = timeinfo2.tm_mday;
                int month2 = timeinfo2.tm_mon + 1;
                int year2 = timeinfo2.tm_year + 1900;

                if (day1 == day2 && month1 == month2 && year1 == year2) {
                    cout << "Measurements taken into account : " << endl << *m;
                    selectedMeasurements.push_back(m);
                }
    }
    
    return selectedMeasurements;
}

void Sensor :: addMeasurement(Measurement* m) {
    measurements.push_back(m);
}

bool Sensor :: operator==(const Sensor* s)const{
    return (name==(s->name));
}

bool Sensor :: operator==(const Sensor& s)const{
    return (name==(s.name));
}
