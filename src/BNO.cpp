#include "BNO.h"

BNO::BNO() {
  bno = Adafruit_BNO055(55, 0x28);
}

BNO::BNO(int address) {
  bno = Adafruit_BNO055(55, address);
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
  imu::Quaternion quat = bno.getQuat();
  imu::Vector<3> euler;
  quat.normalize();
  //wait for 2 second till the sensor is stable
  for(int i = 0; i < 20; i++) {
    quat = bno.getQuat();
    quat.normalize();
    euler = quat.toEuler();
    delay(100);
  }
  yawOffset = euler.x() * 180 / M_PI;
  pitchOffset = euler.y() * 180 / M_PI;
  rollOffset = euler.z() * 180 / M_PI;
}

void BNO::readSensor() {
  // Get new data from the BNO sensor
  //Get the orientation angles
  imu::Quaternion quat = bno.getQuat();
  quat.normalize();
  imu::Vector<3> euler = quat.toEuler();
  yaw = euler.x() * 180 / M_PI - yawOffset;
  pitch = euler.y() * 180 / M_PI - pitchOffset;
  roll = euler.z() * 180 / M_PI - rollOffset;
  
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
  Serial.print("Yaw: ");
  Serial.print(yaw);
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
  Serial.print("Temperature: ");
  Serial.println(temperature);
}

float BNO::getYaw() {
  return yaw;
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
