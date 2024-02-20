#ifndef BME280_h
#define BME280_h

#include "SparkFunBME280.h"

class BME280{
    public:
    BME280();
    bool begin();
    float readTempC();
    float readFloatPressure();
    float readFloatAltitudeFeet();
};

#endif


