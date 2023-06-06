#include <list>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <typeinfo>
#include <ctime>
#ifdef PERF
    #include <chrono>
#endif
using namespace std;

#include "System.h"
#include "Device.h"
#include "Sensor.h"
#include "Coordinates.h"
#include "Conversions.h"
#include "PrivateUser.h"
#include "Values.h"
#include "Measurement.h"

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

    #ifdef PERF
        auto start = chrono::high_resolution_clock::now();
    #endif

    //Initialisation des Sensors
    initializeSensors(ficSensors);

    //Initialisation des Cleaners
    initializeCleaners(ficCleaners);

    //Initialisation des PrivateUsers
    initializePrivateUsers(ficPrivateUsers);

    //Initialisation des Mesures
    initializeMeasurements(ficMeasurements);

    #ifdef PERF
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Temps d'exécution System(const string ficSensors, const string ficCleaners, const string ficPrivateUsers, const string ficMeasurements) : " << duration.count() << " ms" << endl;
    #endif
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

    #ifdef PERF
        auto start = chrono::high_resolution_clock::now();
    #endif

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
                coord.latitude=stof(latitude);
                coord.longitude=stof(longitude);
                devices.push_back(new Sensor(name, coord));
            }
        }
    } else {
        cout << "Error: sensors file not found." << endl;
    }

    #ifdef PERF
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Temps d'exécution initializeSensors(const string fileName) : " << duration.count() << " ms" << endl;
    #endif
}

void System::initializeCleaners(const string fileName) {

    #ifdef PERF
        auto start = chrono::high_resolution_clock::now();
    #endif

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
        cout << "Error: cleaners file not found." << endl;
    }

    #ifdef PERF
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Temps d'exécution initializeCleaners(const string fileName) : " << duration.count() << " ms" << endl;
    #endif
}

void System::initializePrivateUsers(const string fileName) {

    #ifdef PERF
        auto start = chrono::high_resolution_clock::now();
    #endif

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
        cout << "Error: users file not found." << endl;
    }

    #ifdef PERF
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Temps d'exécution initializePrivateUsers(const string fileName) : " << duration.count() << " ms" << endl;
    #endif
}

int System :: addSensorToPrivateUser(string name, Sensor* monSensor){
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

    #ifdef PERF
        auto start = chrono::high_resolution_clock::now();
    #endif

    ifstream file;
    file.open(fileName);
    Values value;
    time_t date;

    string dateMesure="";
    string nomSensor="";
    string att="";
    string val="";
    string bin;

    string dateMesure2="";
    string nomSensor2="";
    string att2="";
    string val2="";

    if (file) {
        while ( getline(file,dateMesure,';') && getline(file,nomSensor,';') && getline(file,att,';') && getline(file,val,';') && getline(file,bin) ) {

            if (dateMesure!="" && nomSensor!="" && att!="" && val!=""){
                value.o3=0;
                value.no2=0;
                value.so2=0;
                value.pm10=0;
                if (att == "O3") {
                    value.o3=stof(val);
                } else if (att == "NO2") {
                    value.no2=stof(val);
                } else if (att == "SO2") {
                    value.so2=stof(val);
                } else if (att == "PM10") {
                    value.pm10=stof(val);
                }

                for (int i = 0; i < 3; i++) {
                    if ( getline(file,dateMesure2,';') && getline(file,nomSensor2,';') && getline(file,att2,';') && getline(file,val2,';') &&getline(file,bin) ) {
                        if (dateMesure2 == dateMesure && nomSensor2 == nomSensor && att2 != att) {
                            if (att2 == "O3") {
                                value.o3=stof(val2);
                            } else if (att2 == "NO2") {
                                value.no2=stof(val2);
                            } else if (att2 == "SO2") {
                                value.so2=stof(val2);
                            } else if (att2 == "PM10") {
                                value.pm10=stof(val2);
                            }
                        } else if (dateMesure2!="" && nomSensor2!="" && att2!="" && val2!="") {
                            Values value2;
                            value2.o3=0;
                            value2.no2=0;
                            value2.so2=0;
                            value2.pm10=0;
                            if (att == "O3") {
                                value2.o3=stof(val2);
                            } else if (att == "NO2") {
                                value2.no2=stof(val2);
                            } else if (att == "SO2") {
                                value2.so2=stof(val2);
                            } else if (att == "PM10") {
                                value2.pm10=stof(val2);
                            }

                            date=stringToTime_t(dateMesure2);

                            for (const auto & device : devices) {
                                if (Sensor* sensor = dynamic_cast<Sensor*>(device)) {
                                    if (sensor->getName() == nomSensor2) {
                                        sensor->addMeasurement(new Measurement(value2,date));
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }



                date=stringToTime_t(dateMesure);

                for (const auto & device : devices) {
                    if (Sensor* sensor = dynamic_cast<Sensor*>(device)) {
                        if (sensor->getName() == nomSensor) {
                            sensor->addMeasurement(new Measurement(value,date));
                            break;
                        }
                    }
                }
            }
        }

    } else {
        cout << "Error: measurements file not found." << endl;
    }

    #ifdef PERF
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Temps d'exécution initializeMeasurements(const string fileName) : " << duration.count() << " ms" << endl;
    #endif
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

list<Cleaner*> System::getCleaners() const {
    list<Cleaner*> cleaners;
    for (const auto & device : devices) {
        if (Cleaner* cleaner = dynamic_cast<Cleaner*>(device)) {
            cleaners.push_back(cleaner);
        }
    }
    return cleaners;
}

list<PrivateUser*> System::getPrivateUsers() const {
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

void System::blacklistSensor(Sensor *s) {

    #ifdef PERF
        auto start = chrono::high_resolution_clock::now();
    #endif

    s->setBlacklistedSensor(true);
    blacklistedSensors.push_back(s);

    #ifdef PERF
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Temps d'exécution blacklistSensor(Sensor *s) : " << duration.count() << " ms" << endl;
    #endif
}

void System::unBlacklistSensor(Sensor *s) {

    #ifdef PERF
        auto start = chrono::high_resolution_clock::now();
    #endif

    s->setBlacklisted(false);
    blacklistedSensors.remove(s);
    PrivateUser* user =s->getPrivateUser();
    bool ok=true;
    if(user!=nullptr){
        list<Sensor*> listSensorsUser = user->getSensors();
        for(const auto & sensorUser : listSensorsUser){
            for ( const auto & sensorBL : blacklistedSensors){
                if((*sensorUser)==(*sensorBL)) {
                    break;
                    ok=false;
                }
            }
        }
        if(ok){
            user->unBlacklistedUser(false);
        } else if (user!=nullptr){
            s->setBlacklisted(true);
        }
    }

    #ifdef PERF
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Temps d'exécution unBlacklistSensor(Sensor *s) : " << duration.count() << " ms" << endl;
    #endif
}

Sensor* System::getSensorsByName(string n) {
    Sensor* s;
    for(const auto & sensor : getSensors()){
        if(sensor->getName()==n){
            s=sensor;
            break;
        }
    }
    return s;
}
