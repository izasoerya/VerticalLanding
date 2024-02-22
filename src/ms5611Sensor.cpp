#include "ms5611Sensor.h"

ms5611Sensor::ms5611Sensor(){
    ms5611 = MS5611();
}

void ms5611Sensor::begin(){
    while(!ms5611.begin())
    {
        Serial.print("No MS5611 detected ...");
        delay(500);
    }
    ms5611.setOversampling(OSR_ULTRA_HIGH);
}

float ms5611Sensor::readPressure(){
    return ms5611.getPressure();
}

float ms5611Sensor::getAltitude(double pressure, double basePressure){
    return (44330.0f * (1.0f - pow((double)pressure / (double)basePressure, 0.1902949f)));
}