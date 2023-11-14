#ifndef BNO_H
#define BNO_H

#include <Adafruit_BNO055.h>
#include <quaternion.h>

class BNO{
  public:
    BNO();
    BNO(int address);
    void begin();
    void calibrate();
    void readSensor();
    void printResult();
    float getYaw();
    float getRoll();
    float getPitch();
    float getAccelerationX();
    float getAccelerationY();
    float getAccelerationZ();
    float getTemperature();
    
  private:
    Adafruit_BNO055 bno;
    float yaw;
    float roll;
    float pitch;
    float yawOffset;
    float pitchOffset;
    float rollOffset;
    float accelerationX;
    float accelerationY;
    float accelerationZ;
    float temperature;
};

#endif
