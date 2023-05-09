# /*************************************************************************
#                               AgencyEmployee - interface
#                              -------------------
#     début                : 9 mai 2023
#     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
#     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
# *************************************************************************/

//---------- Interface de la classe <AgencyEmployee> (fichier AgencyEmployee.h) ----------------
#if ! defined ( AgencyEmployee_H )
#define AgencyEmployee_H

//--------------------------------------------------- Interfaces utilisées
#include "Device.h"
#include <string.h>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AgencyEmployee>
//
//
//------------------------------------------------------------------------

class AgencyEmployee : public User
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
    AgencyEmployee & operator = ( const AgencyEmployee & unAgencyEmployee );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    AgencyEmployee ( const AgencyEmployee & unAgencyEmployee );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AgencyEmployee ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AgencyEmployee ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  provider Provider;
};

//-------------------------------- Autres définitions dépendantes de <AgencyEmployee>

#endif // AgencyEmployee_H
