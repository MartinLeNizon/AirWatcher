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

#include <list>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <typeinfo>

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
    ifstream file(fileName.c_str());
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

list<Device*> System::getDevices() {
    return devices;
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
} //----- Fin de ~System


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
