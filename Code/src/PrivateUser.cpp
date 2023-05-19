/*************************************************************************
                           PrivateUser  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <PrivateUser> (fichier PrivateUser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "PrivateUser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



//-------------------------------------------- Constructeurs - destructeur
PrivateUser::PrivateUser ( const PrivateUser & unPrivateUser )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <PrivateUser>" << endl;
    #endif
    name=unPrivateUser.name;
    surname=unPrivateUser.surname;
    mail=unPrivateUser.mail;
    password=unPrivateUser.password;
    blacklisted=unPrivateUser.blacklisted;
    points=unPrivateUser.points;

} //----- Fin de PrivateUser (constructeur de copie)


PrivateUser::PrivateUser ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <PrivateUser>" << endl;
    #endif
} //----- Fin de PrivateUser

PrivateUser :: PrivateUser (string name, string nomSensor) : User(name){
    addSensor(nomSensor);
    points=0;
    blacklisted=0;
}

PrivateUser::PrivateUser (string nom, long point, string nomSensor) : User(nom)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PrivateUser>" << endl;
#endif

    points=point;
    addSensor(nomSensor);

} //----- Fin de PrivateUser

ostream & operator << (ostream & os, const PrivateUser &u){
    os << u.name << "; blacklisted : "<<u.blacklisted<<"; points : "<< u.points <<";Sensors :"<<u.getSensors();
    return os;
}

string PrivateUser :: getSensors()const{
    string listeSensors="";
    int nbSensor=0;
    
    for (const auto& elem : sensors) {
        if(nbSensor!=0){
            listeSensors+="|";
        }
        listeSensors+=elem;
        nbSensor++;
    }

    return listeSensors;
}

void PrivateUser :: addSensor(string name){
    sensors.push_back(name);
}

PrivateUser::~PrivateUser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PrivateUser>" << endl;
#endif
} //----- Fin de ~PrivateUser


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
