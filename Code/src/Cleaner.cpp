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
#include "Conversions.h"

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

Cleaner::Cleaner (string nom, Coordinates pos, time_t start, time_t stop) : Device(nom,pos)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif

    startTime=start;
    stopTime=stop;
} //----- Fin de Cleaner

// TODO: Incomplète
istream & operator >> (istream & is, Cleaner & c){
    string res1="";
    string res2="";
    string res3="";
    string res4="";
    string res5="";
    getline(is,res1,';');
    getline(is,res2,';');
    getline(is,res3,';');
    getline(is,res4,';');
    getline(is,res5,';');

    if (res1!="" && res2!="" && res3!="" && res4!="" && res5!=""){
        c.name = res1;
        c.position.longitude=stof(res2);
        c.position.latitude=stof(res3);
    }
    // Reste à faire la gestion des dates

    return is;
}

ostream & operator << (ostream & os, const Cleaner &c){
    string startDate;
    string stopDate;
     
    startDate=time_tToString(c.startTime);
    stopDate=time_tToString(c.stopTime);
    
    os << c.name << ";" << c.position.longitude << ";" << c.position.latitude << ";"<<startDate<<";"<<stopDate<<";";
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