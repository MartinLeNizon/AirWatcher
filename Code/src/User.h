#if ! defined ( User_H )
#define User_H

#include "Device.h"
#include <string>

class User {

public:

//-------------------------------------------- Constructeurs - destructeur

    User(const User & unUser);

    User(string nom);

    User();
    
    virtual ~User ( );

//------------------------------------------------- Surcharge d'opérateurs

    User & operator = ( const User & unUser );

//-------------------------------------------------------- Autres méthodes

    friend ostream & operator << (ostream & os, const User &u);

    string getName() const;

protected:
  string name;
  string surname;
  string mail;
  string password;

};

#endif
