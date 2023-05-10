/*************************************************************************
                           System  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <System> (fichier System.h) ----------------
#if ! defined ( System_H )
#define System_H

//--------------------------------------------------- Interfaces utilisées
#include "Device.h"
#include "Sensor.h"
#include "User.h"
#include "Provider.h"
#include <list>
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <System>
//
//
//------------------------------------------------------------------------

class System
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
    System & operator = ( const System & unSystem );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    System ( const System & unSystem );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    void initializeSensors(const string nomFic);

    list<Device> getListDevice()const;

    void afficherListDevice()const;

    void addDevice(const Device & d);

    System ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~System ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  list<Device> liste_device;
  list<User> liste_user;
  list<Provider> liste_provider;



};

//-------------------------------- Autres définitions dépendantes de <System>

#endif // System_H
