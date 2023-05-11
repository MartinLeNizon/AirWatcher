# /*************************************************************************
#                               Sensor - réalisation
#                              -------------------
#     début                : 9 mai 2023
#     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
#     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
# *************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Sensor.h"
#include "Device.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Sensor::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
Sensor::Sensor ( const Sensor & unSensor )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
} //----- Fin de Sensor (constructeur de copie)


Sensor::Sensor()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif

    blacklisted = false;
} //----- Fin de Sensor

Sensor::Sensor (string nom, Coordinates pos) : Device(nom,pos)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif

    blacklisted = false;
} //----- Fin de Sensor

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


Sensor::~Sensor ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif
} //----- Fin de ~Sensor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées