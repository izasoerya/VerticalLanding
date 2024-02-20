#ifndef BME280_h
#define BME280_h

#include "SparkFunBME280.h"

class BME
{
private:
    BME280 bme;

public:
    BME();
    void begin();
    float getTemperature();
    float getPressure();
    float getAltitude();
};

#endif
