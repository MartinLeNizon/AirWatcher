#ifndef Zone_H
#define Zone_H

#include "Coordinates.h"

using namespace std;

typedef struct {

    Coordinates center;
    float radius;

    bool isInside(Coordinates coordinates) {
        bool inside = false;
        if (coordinates.distanceTo(center) <= radius) inside = true;
        return inside;
    }

    float getDistanceFromCenter(Coordinates coordinates) {
        return coordinates.distanceTo(center);
    }

} Zone;

#endif