#if ! defined ( Device_H )
#define Device_H

#include <string>
using namespace std;

#include "Coordinates.h"

class Device {
    
public:

//-------------------------------------------- Constructeurs - destructeur

    Device(const Device & unDevice);

    Device();

    Device (string nom, Coordinates pos);

    virtual ~Device();

//------------------------------------------------- Surcharge d'opérateurs

    friend istream & operator >> (istream & is, Device &d);

    friend ostream & operator << (ostream & os, const Device &d);

//-------------------------------------------------------- Autres méthodes

    string getName() const;

    Coordinates getPosition() const;

protected:
    string name;
    Coordinates position;
};

#endif

