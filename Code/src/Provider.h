# /*************************************************************************
#                               Provider - interface
#                              -------------------
#     début                : 9 mai 2023
#     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
#     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
# *************************************************************************/

//---------- Interface de la classe <Provider> (fichier Provider.h) ----------------
#if ! defined ( Provider_H )
#define Provider_H

//--------------------------------------------------- Interfaces utilisées
#include "Device.h"
#include <iostream>
#include <string>
#include <list>
#include "Cleaner.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Provider>
//
//
//------------------------------------------------------------------------

class Provider
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //



//-------------------------------------------- Constructeurs - destructeur
    Provider ( const Provider & unProvider );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Provider ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Provider ( );
    // Mode d'emploi :
    //
    // Contrat :
    //



//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  string name;
  list<int> Cleaners;

};

//-------------------------------- Autres définitions dépendantes de <Provider>

#endif // Provider_H
