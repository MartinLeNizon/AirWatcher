# /*************************************************************************
#                               Sensor - interface
#                              -------------------
#     début                : 9 mai 2023
#     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
#     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
# *************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if ! defined ( Sensor_H )
#define Sensor_H

//--------------------------------------------------- Interfaces utilisées
#include "Device.h"
#include "PrivateUser.h"
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
//
//
//------------------------------------------------------------------------
class PrivateUser;

class Sensor : public Device
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getName() const;
    // Mode d'emploi : Permet d'accéder à l'attribut name du sensor
    //
    // Contrat :
    //

    bool getBlacklisted() const;
    // Mode d'emploi : Permet d'accéder à l'attribut blacklisted du sensor
    //
    // Contrat :
    //

    void setBlacklisted( bool blacklist ) ;
    // Mode d'emploi : Permet de blacklister ou d'unblacklister un sensor
    //
    // Contrat :
    //

    void setBlacklistedSensor( bool blacklist ) ;
    // Mode d'emploi : Permet de blacklister ou d'unblacklister un sensor
    //
    // Contrat :
    //

    PrivateUser* getPrivateUser() const;
    // Mode d'emploi : Permet d'accéder à l'attribut user du sensor
    //
    // Contrat :
    //

    void setPrivateUser( PrivateUser* monUser ) ;
    // Mode d'emploi : Permet de setter l'user d'un sensor
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Sensor & operator = ( const Sensor & unSensor );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Sensor ( const Sensor & unSensor );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Sensor (string nom, Coordinates pos);

    friend istream & operator >> (istream & is, Sensor &d);
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend ostream & operator << (ostream & os, const Sensor &s);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Sensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Sensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
bool blacklisted;
PrivateUser* user;

};

//-------------------------------- Autres définitions dépendantes de <Sensor>

#endif // Sensor_H

