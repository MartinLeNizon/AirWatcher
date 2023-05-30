#include <iostream>
#include <string>
using namespace std;

#include "Device.h"

//-------------------------------------------- Constructeurs - destructeur

Device::Device(const Device & unDevice) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Device>" << endl;
#endif
}

Device::Device() {
#ifdef MAP
    cout << "Appel au constructeur de <Device>" << endl;
#endif
}

Device::Device(string nom, Coordinates pos) {
#ifdef MAP
    cout << "Appel au constructeur de <Device>" << endl;
#endif

    name=nom;
    position=pos;
}

Device::~Device() {
#ifdef MAP
    cout << "Appel au destructeur de <Device>" << endl;
#endif
}



//------------------------------------------------- Surcharge d'opérateurs

ostream & operator << (ostream & os, const Device &d){
    os << d.name << ";" << d.position.longitude << ";" << d.position.latitude << ";";
    return os;
}

//-------------------------------------------------------- Autres méthodes

string Device :: getName()const{
    return name;
}

Coordinates Device :: getPosition ()const{
    return position;
}
