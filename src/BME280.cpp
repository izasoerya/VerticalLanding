#include "BME280.h"

BME::BME() : bme(BME280())
{
  bme.setI2CAddress(0x76);
}

void BME::begin()
{
  if (bme.beginI2C() == false) // Begin communication over I2C
  {
    Serial.println("The sensor did not respond. Please check wiring.");
  }
}

float BME::getTemperature()
{
  return bme.readTempC();
}

float BME::getPressure()
{
  return bme.readFloatPressure();
}

void BME::setCurrentPressure()
{
  bme.setReferencePressure(bme.readFloatPressure());
}

float BME::getAltitude()
{
  return bme.readFloatAltitudeMeters();
}