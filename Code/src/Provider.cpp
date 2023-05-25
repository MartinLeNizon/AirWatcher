
#include <iostream>

#include "Provider.h"
#include "Device.h"
#include "Cleaner.h"
#include <string>
using namespace std;

//-------------------------------------------- Constructeurs - destructeur

Provider::Provider(const Provider & unProvider) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Provider>" << endl;
#endif
}

Provider::Provider() {
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif
}

Provider::Provider(string n) {
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif
    name=n;
}

//-------------------------------------------------------- Autres méthodes

void Provider :: ajouterCleaner(Cleaner c) {
    Cleaners.push_back(c);
}

void Provider :: supprimerCleaner(Cleaner c) {
    Cleaners.remove(c);
}

string Provider :: getName() {
    return name;
}

list<Cleaner> Provider :: getCleaners() {
    return Cleaners;
}


Provider::~Provider() {
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif
}
