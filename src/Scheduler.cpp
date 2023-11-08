#include "Scheduler.h"

TaskScheduler::TaskScheduler(){}

void TaskScheduler::createTask(uint8_t idTask, String name, uint16_t delay)
{
    taskData[iterationTask].idTask = idTask;
    taskData[iterationTask].name = name;
    taskData[iterationTask].delay = delay;
    iterationTask++;
}

void TaskScheduler::runTask(createTaskParam taskData)
{
    if(millis() - prevMillis > taskData.delay)
    {
        prevMillis = millis();
        Serial.println(taskData.name);
    }
        
}