
#include <iostream>
using namespace std;

#include "Cleaner.h"
#include "Device.h"
#include <cmath> 
#include "Conversions.h"

//-------------------------------------------- Constructeurs - destructeur

Cleaner::Cleaner ( const Cleaner & unCleaner ) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cleaner>" << endl;
#endif
    startTime=unCleaner.startTime;
    stopTime=unCleaner.stopTime;
    position=unCleaner.position;
}


Cleaner::Cleaner() {
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
}

Cleaner::Cleaner (string nom, Coordinates pos, time_t start, time_t stop) : Device(nom,pos) {
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif

    startTime=start;
    stopTime=stop;
}

Cleaner::~Cleaner() {
#ifdef MAP
    cout << "Appel au destructeur de <Cleaner>" << endl;
#endif
}


// TODO: Incomplète
istream & operator >> (istream & is, Cleaner & c) {
    string res1="";
    string res2="";
    string res3="";
    string res4="";
    string res5="";
    getline(is,res1,';');
    getline(is,res2,';');
    getline(is,res3,';');
    getline(is,res4,';');
    getline(is,res5,';');

    if (res1!="" && res2!="" && res3!="" && res4!="" && res5!=""){
        c.name = res1;
        c.position.longitude=stof(res2);
        c.position.latitude=stof(res3);
    }
    // Reste à faire la gestion des dates

    return is;
}

ostream & operator << (ostream & os, const Cleaner &c){
    string startDate;
    string stopDate;
     
    startDate=time_tToString(c.startTime);
    stopDate=time_tToString(c.stopTime);
    
    os << c.name << ";" << c.position.longitude << ";" << c.position.latitude << ";"<<startDate<<";"<<stopDate<<";";
    return os;
}

bool Cleaner :: operator == (const Cleaner& c) const {
        return (startTime == c.startTime) && 
               (stopTime == c.stopTime) &&
               (fabs(position.latitude - c.position.latitude) < 0.0001) && 
               (fabs(position.longitude - c.position.longitude) < 0.0001);
}