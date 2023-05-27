
#include <iostream>
#include <cmath>
using namespace std;

#include "Measurement.h"
#include "Conversions.h"
#include "Values.h"

//-------------------------------------------- Constructeurs - destructeur

Measurement::Measurement(const Measurement & unMeasurement) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Measurement>" << endl;
#endif
}


Measurement::Measurement() {
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif
}

Measurement::Measurement(Values aValue, time_t dateMesure) {
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
    values = aValue;
    date=dateMesure;
}

Measurement::~Measurement() {
#ifdef MAP
    cout << "Appel au destructeur de <Measurement>" << endl;
#endif
}

//------------------------------------------------- Surcharge d'opérateurs

Measurement & Measurement::operator = (const Measurement & unMeasurement) {}

istream & operator >> (istream & is, Measurement & c){}

ostream & operator << (ostream & os, const Measurement &c){
    string date;
     
    date=time_tToString(c.date);
    
    os << "o3 :"  << c.values.o3 << " no2 :"  << c.values.no2 << " so2 :"  << c.values.so2 << " pm10 :"  << c.values.pm10 << endl << date << endl;
    return os;
}

//-------------------------------------------------------- Autres méthodes

Values Measurement::getValues() {
    return values;
}