/*************************************************************************
                           User  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <User> (fichier User.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



//-------------------------------------------- Constructeurs - destructeur
User::User ( const User & unUser )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <User>" << endl;
    #endif
    name=unUser.name;
    surname=unUser.surname;
    mail=unUser.mail;
    password=unUser.password;

} //----- Fin de User (constructeur de copie)


User::User ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <User>" << endl;
    #endif
} //----- Fin de User

User::User (string nom)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif

    name=nom;

} //----- Fin de User

ostream & operator << (ostream & os, const User &u){
    os << u.name << ";" << u.surname << ";" << u.mail << ";";
    return os;
}

string User :: getName()const{
    return name;
}



User::~User ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <User>" << endl;
#endif
} //----- Fin de ~User


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
