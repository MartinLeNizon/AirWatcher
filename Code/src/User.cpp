#include <iostream>
#include <string>
using namespace std;

#include "User.h"



//-------------------------------------------- Constructeurs - destructeur
User::User(const User & unUser) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <User>" << endl;
#endif
    name=unUser.name;
    surname=unUser.surname;
    mail=unUser.mail;
    password=unUser.password;
}

User::User() {
#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif
}

User::User(string nom) {
#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif
    name=nom;
}

User::~User() {
#ifdef MAP
    cout << "Appel au destructeur de <User>" << endl;
#endif
}

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator << (ostream & os, const User &u) {
    os << u.name << ";" << u.surname << ";" << u.mail << ";";
    return os;
}

//-------------------------------------------------------- Autres méthodes

string User :: getName() const {
    return name;
}
