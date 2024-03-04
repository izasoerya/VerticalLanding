#include <Arduino.h>
#include <Scheduler.h>
#include "BNO.h"
#include "BME280.h"
#include "bmp3XX.h"

void dataBMEFunc();
void dataBNOFunc();
void dataBMPFunc();

TaskScheduler dataBME(1, "dataBME", 1000, dataBMEFunc);
TaskScheduler dataBMP(2, "dataBMP", 1000, dataBMPFunc);
TaskScheduler dataBNO(3, "dataBNO", 1000, dataBNOFunc);

BNO bno;
BME bme;
SensorBMP bmp;
float basePressure;
int i = 0;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    bno.begin();
    bno.calibrate();
    bme.begin();
    bme.getTemperature();
    bme.setCurrentPressure();
    bmp.begin();
    bmp.getTemperature();
    basePressure = bme.getPressure();
}

void loop()
{
    // put your main code here, to run repeatedly:
    dataBME.runTask();
    dataBNO.runTask();
    dataBMP.runTask();
}

void dataBMEFunc()
{
    float temperature = bme.getTemperature();
    float pressure = bme.getPressure();
    float altitude = bme.getAltitude();

    Serial.println("====== BME280 ======");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" Pressure: ");
    Serial.print(pressure);
    Serial.print(" Altitude: ");
    Serial.println(altitude);
    Serial.println();
}

void dataBNOFunc()
{
    bno.readSensor();
    float angleX = bno.getRoll();
    float angleY = bno.getPitch();
    float angleZ = bno.getYaw();

    Serial.println("====== BNO055 ======");
    Serial.print("Roll: ");
    Serial.print(angleX);
    Serial.print(" Pitch: ");
    Serial.print(angleY);
    Serial.print(" Yaw: ");
    Serial.println(angleZ);
    Serial.println();
}

void dataBMPFunc()
{
    float temperature = bmp.getTemperature();
    float pressure = bmp.getPressure();
    float altitude = bmp.getAltitude(basePressure / 100.0F);

    Serial.println("====== BMP388 ======");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" Pressure: ");
    Serial.print(pressure);
    Serial.print(" Altitude: ");
    Serial.println(altitude);
    Serial.println();
}