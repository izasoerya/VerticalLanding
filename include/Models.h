#ifndef MODELS_H
#define MODELS_H

enum rocketState
{
    initialization = 1,
    flying = 2,
    landing = 3,
};

struct DataType
{
    float angleX;
    float angleY;
    float angleZ;
    float altitude;
    char *state;
};

#endif