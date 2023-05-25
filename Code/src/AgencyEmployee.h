
#if ! defined ( AgencyEmployee_H )
#define AgencyEmployee_H

#include <string.h>

class AgencyEmployee : public User {

public:

//-------------------------------------------- Constructeurs - destructeur

    AgencyEmployee(const AgencyEmployee & unAgencyEmployee);

    AgencyEmployee();

    virtual ~AgencyEmployee();


//------------------------------------------------- Surcharge d'opérateurs

    AgencyEmployee & operator = (const AgencyEmployee & unAgencyEmployee);


protected:

};

#endif
