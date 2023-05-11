# /*************************************************************************
#                               Cleaner - réalisation
#                              -------------------
#     début                : 9 mai 2023
#     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
#     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
# *************************************************************************/

//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Cleaner.h"
#include "Device.h"
#include <cmath> 

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Cleaner::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
Cleaner::Cleaner ( const Cleaner & unCleaner )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cleaner>" << endl;
#endif
    startTime=unCleaner.startTime;
    stopTime=unCleaner.stopTime;
    position=unCleaner.position;
} //----- Fin de Cleaner (constructeur de copie)


Cleaner::Cleaner()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
} //----- Fin de Cleaner

// TODO: Incomplète
istream & operator >> (istream & is, Device & d){
    string res1="";
    string res2="";
    string res3="";
    string bin;
    getline(is,res1,';');
    getline(is,res2,';');
    getline(is,res3,';');
    getline(is,bin,';');
    getline(is,bin,';');

    if (res1!="" && res2!="" && res3!=""){
        d.name = res1;
        d.position.longitude=stof(res2);
        d.position.latitude=stof(res3);
    }

    return is;
}

ostream & operator << (ostream & os, const Cleaner &s){
    os << s.name << ";" << s.position.longitude << ";" << s.position.latitude << ";";
    return os;
}

bool Cleaner :: operator == (const Cleaner& c) const {
        return (startTime == c.startTime) && 
               (stopTime == c.stopTime) &&
               (fabs(position.latitude - c.position.latitude) < 0.0001) && 
               (fabs(position.longitude - c.position.longitude) < 0.0001);
    }


Cleaner::~Cleaner()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cleaner>" << endl;
#endif
} //----- Fin de ~Cleaner


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées