#ifndef ms5611Sensor_H
#define ms5611Sensor_H

#include "MS5611.h"

class ms5611Sensor{
    public:
        ms5611Sensor();
        void begin();
        void read();
        float getPressure();
        float getAltitude(double pressure, double basePressure);
    private:
    MS5611 ms5611;
};

#endif