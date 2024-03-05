#ifndef MODELS_H
#define MODELS_H

enum rocketState
{
    initialization = 1,
    flying = 2,
    landing = 3,
};

struct FlightData
{
    float angleX;
    float angleY;
    float angleZ;
    float altitudeBMP;
    float temperatureBMP;
    float pressureBMP;
    float altitudeBME;
    float temperatureBME;
    float basePressure;
    float pressureBME;
};

#endif