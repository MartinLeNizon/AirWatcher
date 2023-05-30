#ifndef Values_H
#define Values_H

#include <string>
#include <iostream>

using namespace std;

typedef struct{
    float o3;
    float no2;
    float so2;
    float pm10;

    void create(float o3, float no2, float so2, float pm10) {
        this->o3 = o3;
        this->no2 = no2;
        this->so2 = so2;
        this->pm10 = pm10;
    }
} Values;

#endif