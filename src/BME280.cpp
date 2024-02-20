#include "BME280.h"
#include "SparkFunBME280.h"

BME280::BME280(){

}

bool BME280::begin(){
    if (BME280.beginI2C() == false) //Begin communication over I2C
  {
    Serial.println("The sensor did not respond. Please check wiring.");
    while (1); //Freeze
  }
}

float BME280::readTempC(){
    return BME280.readTempC;
}

flaot BME280::readFloatPressure(){
    return BME280.readFloatPressure;
}

float BME280::readFloatAltitudeFeet(){
    return BME280.readFloatAltitudeFeet;
}