
#include <iostream>
using namespace std;

#include "Measurement.h"
#include <cmath> 
#include "Conversions.h"

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
    value = aValue;
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
    
    os << "o3 :"  << c.value.o3 << " no2 :"  << c.value.no2 << " so2 :"  << c.value.so2 << " pm10 :"  << c.value.pm10 << endl << date << endl;
    return os;
}





