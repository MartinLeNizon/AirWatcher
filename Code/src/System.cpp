using namespace std;

#include "System.h"
#include "Device.h"
#include "Sensor.h"
#include "Coordinates.h"
#include "Conversions.h"
#include "PrivateUser.h"
#include "Values.h"
#include "Measurement.h"


#include <list>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <typeinfo>
#include <ctime>

//-------------------------------------------- Constructeurs - destructeur
System::System(const System & unSystem) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <System>" << endl;
#endif
}


System::System(const string ficSensors, const string ficCleaners, const string ficPrivateUsers, const string ficMeasurements) {
#ifdef MAP
    cout << "Appel au constructeur de <System>" << endl;
#endif

    //Initialisation des Sensors
    initializeSensors(ficSensors);

    //Initialisation des Cleaners
    initializeCleaners(ficCleaners);

    //Initialisation des PrivateUsers
    initializePrivateUsers(ficPrivateUsers);

    //Initialisation des Mesures
    initializeMeasurements(ficMeasurements);
}

System::~System() {
#ifdef MAP
    cout << "Appel au destructeur de <System>" << endl;
#endif

    for (const auto & d : devices) {
        delete d;
    }


    for (const auto & u : users) {
        delete u;
    }


    for (const auto & p : providers) {
        delete p;
    }
} //----- Fin de ~System

//-------------------------------------------------------- Autres méthodes

void System::initializeSensors(const string fileName) {
    ifstream file;
    file.open(fileName);
    Coordinates coord;

    string name="";
    string latitude="";
    string longitude="";
    string bin;

    if (file) {
        while ( getline(file,name,';') && getline(file,latitude,';') && getline(file,longitude,';') && getline(file,bin) ) {
            if (name!="" && latitude!="" && longitude!=""){
                coord.latitude=stof(longitude);
                coord.longitude=stof(latitude);
                devices.push_back(new Sensor(name, coord));
            }
        }
    } else {
        cout << "Error: file not found." << endl;
    }
}

void System::initializeCleaners(const string fileName) {
    ifstream file;
    file.open(fileName);
    Coordinates coord;
    time_t startTime;
    time_t stopTime;

    string name="";
    string latitude="";
    string longitude="";
    string startdate="";
    string stopdate="";
    string bin;

    if (file) {
        while ( getline(file,name,';') && getline(file,latitude,';') && getline(file,longitude,';') && getline(file,startdate,';') && getline(file,stopdate,';') && getline(file,bin) ) {

            if (name!="" && latitude!="" && longitude!="" && startdate!="" &&  stopdate!=""){
                coord.latitude=stof(longitude);
                coord.longitude=stof(latitude);
                startTime=stringToTime_t(startdate);
                stopTime=stringToTime_t(stopdate);
                devices.push_back(new Cleaner(name, coord,startTime,stopTime));
            }
        }
    } else {
        cout << "Error: file not found." << endl;
    }
}

void System::initializePrivateUsers(const string fileName) {
    ifstream file;
    file.open(fileName);

    string name="";
    string nomSensor="";
    string bin;
    int ok;

    Sensor* monSensor;

    if (file) {
        while ( getline(file,name,';') && getline(file,nomSensor,';'), getline(file,bin) ) {
            for (const auto & device : devices) {
                if (Sensor* sensor = dynamic_cast<Sensor*>(device)) {
                    if (sensor->getName() == nomSensor) {
                        monSensor = sensor;
                        break;
                    }
                }
            }
            ok=addSensorToPrivateUser(name, monSensor);
            if (name!="" && nomSensor!="" && ok !=1){
                PrivateUser* newUser= new PrivateUser(name,monSensor);
                monSensor->setPrivateUser(newUser);
                users.push_back(newUser);
            }
        }
    } else {
        cout << "Error: file not found." << endl;
    }
}

int System :: addSensorToPrivateUser (string name, Sensor* monSensor){
    int ok=-1;
    for (const auto& elem : users) {
        if(PrivateUser* pu = dynamic_cast<PrivateUser*>(elem)){
            if ((*pu).getName()==name){
                (*pu).addSensor(monSensor);
                for (const auto & device : devices) {
                    if (Sensor* sensor = dynamic_cast<Sensor*>(device)) {
                        if (sensor->getName() == monSensor->getName()) {
                            sensor->setPrivateUser(pu);
                            break;
                        }
                    }
                }
                ok=1;
            }
        }
    }
    return ok;
}

void System::initializeMeasurements(const string fileName) {
    ifstream file;
    file.open(fileName);
    Values value;
    time_t date;

    string nomSensor="";
    string dateMesure="";
    string att="";
    string val="";
    string bin;

    if (file) {
        while ( getline(file,dateMesure,';') && getline(file,nomSensor,';') && getline(file,att,';') && getline(file,val,';') && getline(file,bin) ) {

            if (dateMesure!="" && nomSensor!="" && att!="" && val!=""){
                if (att == "O3") {
                    value.o3=stof(val);
                } else if (att == "NO2") {
                    value.no2=stof(val);
                } else if (att == "SO2") {
                    value.so2=stof(val);
                } else if (att == "PM10") {
                    value.pm10=stof(val);
                } else {
                }
                date=stringToTime_t(dateMesure);

                for (const auto & device : devices) {
                    if (Sensor* sensor = dynamic_cast<Sensor*>(device)) {
                        if (sensor->getName() == nomSensor) {
                            sensor->addMeasurement(new Measurement(value,date));
                            value.o3=0;
                            value.no2=0;
                            value.so2=0;
                            value.pm10=0;
                            break;
                        }
                    }
                }
            }
        }

    } else {
        cout << "Error: file not found." << endl;
    }
}

list<Device*> System::getDevices() const {
    return devices;
}

list<Sensor*> System::getSensors() const {
    list<Sensor*> sensors;
    for (const auto & device : devices) {
        if (Sensor* sensor = dynamic_cast<Sensor*>(device)) {
            sensors.push_back(sensor);
        }
    }
    return sensors;
}

list<Cleaner*> System :: getCleaners() const{
    list<Cleaner*> cleaners;
    for (const auto & device : devices) {
        if (Cleaner* cleaner = dynamic_cast<Cleaner*>(device)) {
            cleaners.push_back(cleaner);
        }
    }
    return cleaners;
}

list<PrivateUser*> System :: getPrivateUsers() const {
    list<PrivateUser*> pUsers;
    for (const auto & elem : users) {
        if (PrivateUser* pu = dynamic_cast<PrivateUser*>(elem)) {
            pUsers.push_back(pu);
        }
    }
    return pUsers;
}

list<Sensor*> System::getFunctionalSensors() const {
    list<Sensor*> sensors;
    for (const auto & device : devices) {
        if (Sensor* sensor = dynamic_cast<Sensor*>(device)) {
            if (sensor->getBlacklisted() == false) {
                sensors.push_back(sensor);
            }
        }
    }
    return sensors;
}



/*void System::displaySensors() const {
    for (const auto & s : devices) {
        if (typeid(*s).name()=="6Sensor") cout << *s << endl;
    }
}*/
