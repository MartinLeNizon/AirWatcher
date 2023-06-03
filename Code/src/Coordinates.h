#ifndef Coordinates_H
#define Coordinates_H

#include <string>
#include <iostream>
#include <math.h>

using namespace std;

typedef struct Coordinates {

    float latitude;
    float longitude;

    float distanceTo(struct Coordinates coord) {
        #ifdef MAP
            cout << "Distance to : " << (float) sqrt((double)((latitude-coord.latitude)*(latitude-coord.latitude) + (longitude-coord.longitude)*(longitude-coord.longitude))) << endl;
        #endif

        return ((float) sqrt((double)((latitude-coord.latitude)*(latitude-coord.latitude) + (longitude-coord.longitude)*(longitude-coord.longitude))));
    } 

} Coordinates;

#endif