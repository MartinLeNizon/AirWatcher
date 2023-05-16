# /*************************************************************************
#                               System - réalisation
#                              -------------------
#     début                : 9 mai 2023
#     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
#     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
# *************************************************************************/

//---------- Réalisation de la classe <System> (fichier System.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;

//------------------------------------------------------ Include personnel
#include "System.h"
#include "Device.h"
#include "Sensor.h"
#include "Coordinates.h"
#include "Conversions.h"


#include <list>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <typeinfo>
#include <ctime>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type System::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
System::System ( const System & unSystem )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <System>" << endl;
#endif
} //----- Fin de System (constructeur de copie)


System::System()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <System>" << endl;
#endif


} //----- Fin de System

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



/*void System::displaySensors() const {
    for (const auto & s : devices) {
        if (typeid(*s).name()=="6Sensor") cout << *s << endl;
    }
}*/



System::~System()
// Algorithme :
//
{
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


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
