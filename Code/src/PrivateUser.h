# /*************************************************************************
#                               PrivateUser - interface
#                              -------------------
#     début                : 9 mai 2023
#     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
#     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
# *************************************************************************/

//---------- Interface de la classe <PrivateUser> (fichier PrivateUser.h) ----------------
#if ! defined ( PrivateUser_H )
#define PrivateUser_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"
#include "Sensor.h"
#include <string.h>
#include <list>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PrivateUser>
//
//
//------------------------------------------------------------------------
class Sensor;

class PrivateUser : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool getBlacklisted() const;
    // Mode d'emploi : Permet d'accéder à l'attribut blacklisted du sensor
    //
    // Contrat :
    //

    void setBlacklistedUser( bool blacklist ) ;
    // Mode d'emploi : Permet de blacklister ou d'unblacklister un sensor
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    PrivateUser & operator = ( const PrivateUser & unPrivateUser );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    PrivateUser ( const PrivateUser & unPrivateUser );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PrivateUser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    PrivateUser(string nom, long point, Sensor* monSensor);
    PrivateUser(string nom, Sensor* monSensor);

    friend ostream & operator << (ostream & os, const PrivateUser &u);

    //void addSensor(string nomSensor);
    string getSensorsName()const;

    void addSensor(Sensor* s);


    list<Sensor*> getSensors() const;


    virtual ~PrivateUser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  bool blacklisted;
  long points;
  list<Sensor*> sensors;

};

//-------------------------------- Autres définitions dépendantes de <PrivateUser>

#endif // PrivateUser_H
