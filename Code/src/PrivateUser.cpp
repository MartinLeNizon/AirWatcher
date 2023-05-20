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

bool PrivateUser::getBlacklisted() const
// Algorithme : Permet d'accéder à l'attribut blacklisted du sensor
{
    return blacklisted;

} //----- Fin de Méthode

void PrivateUser::setBlacklistedUser(bool blacklist)
{
// Algorithme : Permet de blacklister ou d'unblacklister un user
    blacklisted = blacklist;

    if (blacklist) {
        for (const auto & sensor : sensors) {
            sensor->setBlacklisted(true);
        }
    }
}

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

PrivateUser :: PrivateUser (string name, Sensor* monSensor) : User(name){
    addSensor(monSensor);
    points=0;
    blacklisted=0;
}

PrivateUser::PrivateUser (string nom, long point, Sensor* monSensor) : User(nom)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PrivateUser>" << endl;
#endif

    points=point;
    addSensor(monSensor);

} //----- Fin de PrivateUser

ostream & operator << (ostream & os, const PrivateUser &u){
    os << u.name << "; blacklisted : "<<u.blacklisted<<"; points : "<< u.points <<";Sensors :"<<u.getSensorsName();
    return os;
}

string PrivateUser :: getSensorsName()const{
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
