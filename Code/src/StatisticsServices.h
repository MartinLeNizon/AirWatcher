/*************************************************************************
                           StatisticsServices  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <StatisticsServices> (fichier StatisticsServices.h) ----------------
#if ! defined ( StatisticsServices_H )
#define StatisticsServices_H

//--------------------------------------------------- Interfaces utilisées
#include "Coordinates.h"
#include "Measurement.h"
#include "Values.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <StatisticsServices>
//
//
//------------------------------------------------------------------------

class StatisticsServices
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
    StatisticsServices & operator = ( const StatisticsServices & unStatisticsServices );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    StatisticsServices ( const StatisticsServices & unStatisticsServices );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    StatisticsServices ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~StatisticsServices ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
  Values getAverageAirQuality(Measurement measurements[]);


//----------------------------------------------------- Attributs protégés
Coordinates position;

};

//-------------------------------- Autres définitions dépendantes de <StatisticsServices>

#endif // StatisticsServices_H
