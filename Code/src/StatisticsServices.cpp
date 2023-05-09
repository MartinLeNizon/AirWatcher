# /*************************************************************************
#                               StatisticsServices - réalisation
#                              -------------------
#     début                : 9 mai 2023
#     copyright            : (C) 2023 par Mathis Nguyen, Hugo Saysana, Thibaut Chantrel & Martin Nizon-Deladoeuille
#     e-mails              : mathis.nguyen@insa-lyon.fr ; hugo.saysana@insa-lyon.fr ; thibaut.chantrel@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
# *************************************************************************/

//---------- Réalisation de la classe <StatisticsServices> (fichier StatisticsServices.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "StatisticsServices.h"
#include "Device.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type StatisticsServices::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
StatisticsServices::StatisticsServices ( const StatisticsServices & unStatisticsServices )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <StatisticsServices>" << endl;
#endif
} //----- Fin de StatisticsServices (constructeur de copie)


StatisticsServices::StatisticsServices ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <StatisticsServices>" << endl;
#endif
} //----- Fin de StatisticsServices


StatisticsServices::~StatisticsServices ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <StatisticsServices>" << endl;
#endif
} //----- Fin de ~StatisticsServices


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
Values getAverageAirQuality(Measurement measurements[]){
  float avgO3 = 0, avgNO2 = 0,	avgSO2 = 0,	avgPM10 = 0;
  int nO3 = 0, nNO2 = 0,	nSO2 = 0,	nPM10 = 0;
  Values moyenne;


  return moyenne;
}
