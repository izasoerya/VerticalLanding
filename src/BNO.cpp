#include "BNO.h"

BNO::BNO() {
  bno = Adafruit_BNO055(55, 0x28);
}

void BNO::begin() {
  // Initialize the BNO sensor
  if(!bno.begin()) {
    Serial.print("No BNO055 detected ... Check your wiring!");
    while(1);
  }
}

void BNO::calibrate() {
  // Calibrate the BNO sensor
  imu::Vector<3> euler;
  //wait for 2 second till the sensor is stable
  for(int i = 0; i < 20; i++) {
    euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
    delay(100);
  }
  headingOffset = euler.x();
  rollOffset = euler.y();
  pitchOffset = euler.z();
}

void BNO::readSensor() {
  // Get new data from the BNO sensor
  //Get the orientation angles
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  heading = euler.x() - headingOffset;
  roll = euler.y() - rollOffset;
  pitch = euler.z() - pitchOffset;

  if(heading < 0) {
    heading = 360 + heading;
  }

  if(roll < 0) {
    roll = 360 + roll;
  }

  if(pitch < 0) {
    pitch = 360 + pitch;
  }

  //get the acceleration data
  imu::Vector<3> acceleration = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  accelerationX = acceleration.x();
  accelerationY = acceleration.y();
  accelerationZ = acceleration.z();

  //get the temperature
  temperature = bno.getTemp();
}
void BNO::printResult() {
  // Print the result
  Serial.print("Heading: ");
  Serial.print(heading);
  Serial.print(" Roll: ");
  Serial.print(roll);
  Serial.print(" Pitch: ");
  Serial.println(pitch);
  Serial.print("Acceleration X: ");
  Serial.print(accelerationX);
  Serial.print(" Y: ");
  Serial.print(accelerationY);
  Serial.print(" Z: ");
  Serial.println(accelerationZ);
}
float BNO::getHeading() {
  return heading;
}
float BNO::getRoll() {
  return roll;
}
float BNO::getPitch() {
  return pitch;
}
float BNO::getAccelerationX() {
  return accelerationX;
}
float BNO::getAccelerationY() {
  return accelerationY;
}
float BNO::getAccelerationZ() {
  return accelerationZ;
}
float BNO::getTemperature() {
  return temperature;
}