# /*************************************************************************
#                               Provider - réalisation
#                              -------------------
#     début                : 9 mai 2023
#     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
#     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
# *************************************************************************/

//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Provider.h"
#include "Device.h"
#include "Cleaner.h"
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Provider::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
Provider::Provider ( const Provider & unProvider )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Provider>" << endl;
#endif
} //----- Fin de Provider (constructeur de copie)


Provider::Provider ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif
} //----- Fin de Provider

Provider::Provider (string n)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif
    name=n;
} //----- Fin de Provider

void Provider :: ajouterCleaner (Cleaner c){
    Cleaners.push_back(c);
}

void Provider :: supprimerCleaner (Cleaner c){
    Cleaners.remove(c);
}

string Provider :: getName (){
    return name;
}

list<Cleaner> Provider :: getCleaners (){
    return Cleaners;
}


Provider::~Provider ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif
} //----- Fin de ~Provider



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
