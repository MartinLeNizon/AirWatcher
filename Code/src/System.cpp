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
#include <list>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

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
    Sensor s;

    if (file) {
        while (file >> s && !file.eof()) {
            cout << s;
            sensors.push_back(s);
            cout << "après ajout" << sensors.back();
        }
        cout << endl << "Réussite initialisation"<< endl;
    } else {
        cout << "Fichier non trouvé" << endl;
    }
}

list<Sensor> System::getSensors() const {
    return sensors;
}

void System::displaySensors() const {
    for (const auto & s : sensors) {
        cout << s << endl;
    }
}



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
