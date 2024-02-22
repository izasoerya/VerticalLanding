#include <Arduino.h>
#include <Scheduler.h>
#include "BNO.h"
#include "BME280.h"

void dataBMEFunc();
void dataBNOFunc();

TaskScheduler dataBME(1, "dataMPU", 1000, dataBMEFunc);
TaskScheduler dataBNO(2, "dataBNO", 1000, dataBNOFunc);
BNO bno;
BME bme;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  bno.begin();
  bno.calibrate();
  bme.begin();
  bme.getTemperature();
  bme.setCurrentPressure();
}

void loop()
{
  // put your main code here, to run repeatedly:
  dataBME.runTask();
  dataBNO.runTask();
}

void dataBMEFunc()
{
  float temperature = bme.getTemperature();
  float pressure = bme.getPressure();
  float altitude = bme.getAltitude();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" Pressure: ");
  Serial.print(pressure);
  Serial.print(" Altitude: ");
  Serial.println(altitude);
}

void dataBNOFunc()
{
  bno.readSensor();
  float angleX = bno.getRoll();
  float angleY = bno.getPitch();
  float angleZ = bno.getYaw();

  Serial.print("Roll: ");
  Serial.print(angleX);
  Serial.print(" Pitch: ");
  Serial.print(angleY);
  Serial.print(" Yaw: ");
  Serial.println(angleZ);
}