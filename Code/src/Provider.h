#if ! defined ( Provider_H )
#define Provider_H

#include "Device.h"
#include <iostream>
#include <string>
#include <list>
#include "Cleaner.h"
#include "User.h"

class Provider : public User {

public:

//-------------------------------------------- Constructeurs - destructeur

    Provider(const Provider & unProvider);

    Provider(string n);

    Provider();

    virtual ~Provider();

//-------------------------------------------------------- Autres méthodes

    void ajouterCleaner(Cleaner c);

    void supprimerCleaner(Cleaner c);

    string getName();

    list<Cleaner> getCleaners();

protected:
    std::string name;
    list<Cleaner> Cleaners;

};

#endif
