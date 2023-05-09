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


//------------------------------------------------- Surcharge d'opérateurs
Device & Device::operator = ( const Device & unDevice )
// Algorithme :
//
{
} //----- Fin de operator =


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

