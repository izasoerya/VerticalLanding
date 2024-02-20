#include <Arduino.h>
#include <Scheduler.h>
#include "BNO.h"

void dataBMEFunc();
void dataBNOFunc();

TaskScheduler dataBME(1, "dataMPU", 1000, dataBMEFunc);
TaskScheduler dataBNO(2, "dataBNO", 1000, dataBNOFunc);
BNO bno;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  bno.begin();
  bno.calibrate();
}

void loop()
{
  // put your main code here, to run repeatedly:
  dataBME.runTask();
  dataBNO.runTask();
}

void dataBMEFunc()
{
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