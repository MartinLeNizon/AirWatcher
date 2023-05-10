/*************************************************************************
                           Device  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Device> (fichier Device.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Device.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Device::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


// //------------------------------------------------- Surcharge d'opérateurs
// Device & Device::operator = ( const Device & unDevice )
// // Algorithme :
// //
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Device::Device ( const Device & unDevice )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Device>" << endl;
#endif
} //----- Fin de Device (constructeur de copie)


Device::Device ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Device>" << endl;
#endif
} //----- Fin de Device

Device::Device (string nom, Coordinates pos)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Device>" << endl;
#endif

    name=nom;
    position=pos;
} //----- Fin de Device

istream & operator >> (istream & is, Device & d){
    string res1="";
    string res2="";
    string res3="";
    getline(is,res1,';');
    getline(is,res2,';');
    getline(is,res3,';');
    
    if (res1!="" && res2!="" && res3!=""){
        d.name = res1;
        d.position.longitude=stof(res2);
        d.position.latitude=stof(res3);
    }
    return is;
}

ostream & operator << (ostream & os,const Device &d){
    os <<d.name<<";"<<d.position.longitude<<";"<<d.position.latitude<<";";
    return os;
}

string Device :: getName()const{
    return name;
}

Coordinates Device :: getCoordinates ()const{
    return position;
}



Device::~Device ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Device>" << endl;
#endif
} //----- Fin de ~Device


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

