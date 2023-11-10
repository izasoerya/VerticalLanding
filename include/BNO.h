#ifndef BNO_H
#define BNO_H

#include <Adafruit_BNO055.h>

class BNO{
  public:
    BNO();
    void begin();
    void calibrate();
    void readSensor();
    void printResult();
    float getHeading();
    float getRoll();
    float getPitch();
    float getAccelerationX();
    float getAccelerationY();
    float getAccelerationZ();
    float getTemperature();
    
  private:
    Adafruit_BNO055 bno;
    float heading;
    float roll;
    float pitch;
    float headingOffset;
    float rollOffset;
    float pitchOffset;
    float accelerationX;
    float accelerationY;
    float accelerationZ;
    float temperature;
};

#endif
