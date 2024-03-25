#include "bmp3XX.h"

#define SEALEVELPRESSURE_HPA (1013.25)

BMP::BMP() : bmp(Adafruit_BMP3XX()) {}

bool BMP::begin()
{
    if (bmp.begin_I2C())
    {
        bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_16X);
        bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
        bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
        bmp.setOutputDataRate(BMP3_ODR_50_HZ);
        return true;
    }
    return false;
}

float BMP::getTemperature()
{
    return bmp.temperature;
}

float BMP::getPressure()
{
    return bmp.pressure;
}

float BMP::getAltitude(float basePressure)
{
    return bmp.readAltitude(basePressure);
}

bool BMP::getSensorStatus()
{
    return bmp.performReading();
}