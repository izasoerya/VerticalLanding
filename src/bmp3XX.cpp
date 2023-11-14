#include <Arduino.h>
#include "bmp3XX.h"
#define SEALEVELPRESSURE_HPA (1013.25)
SensorBMP::SensorBMP():bmp(Adafruit_BMP3XX()){}

bool SensorBMP::begin() 
{
    if (!bmp.begin_I2C()) 
    {
        return false;
    }
    else
    {
        bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
        bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
        bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
        bmp.setOutputDataRate(BMP3_ODR_50_HZ);
        return true;        
    }
}

float SensorBMP::getTemperature()
{
    return bmp.temperature;
}

float SensorBMP::getPressure()
{
    return bmp.pressure;
}

float SensorBMP::getAltitude()
{
    return bmp.readAltitude(SEALEVELPRESSURE_HPA);
}