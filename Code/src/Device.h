/*************************************************************************
                           Device  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Device> (fichier Device.h) ----------------
#if ! defined ( Device_H )
#define Device_H

//--------------------------------------------------- Interfaces utilisées
#include "Coordinates.h"

#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Device>
//
//
//------------------------------------------------------------------------

class Device 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    // Device & operator = ( const Device & unDevice );
    // // Mode d'emploi :
    // //
    // // Contrat :
    // //


//-------------------------------------------- Constructeurs - destructeur
    Device ( const Device & unDevice );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Device ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Device ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
std::string name;
Coordinates position;

};

//-------------------------------- Autres définitions dépendantes de <Device>

#endif // Device_H

