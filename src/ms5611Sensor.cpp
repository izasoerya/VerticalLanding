#include "ms5611Sensor.h"

ms5611Sensor::ms5611Sensor(){
    ms5611 = MS5611(0x77);
}

void ms5611Sensor::begin(){
    if (ms5611.begin() == true)
    {
        Serial.println("MS5611 found.");
        ms5611.setOversampling(OSR_ULTRA_HIGH);
    }
    else
    {
        Serial.println("MS5611 not found. halt.");
        while (1);
    }
    Serial.println();
}

void ms5611Sensor::read(){
    ms5611.read();
}

float ms5611Sensor::getPressure(){
    return ms5611.getPressure();
}

float ms5611Sensor::getAltitude(double pressure, double basePressure){
    return ((273.15f + ms5611.getTemperature()) / 0.0065f * (-1.0f + pow((double)basePressure / (double)pressure, 0.19022256039f)));
}