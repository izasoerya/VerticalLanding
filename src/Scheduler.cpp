#include "Scheduler.h"

TaskScheduler::TaskScheduler(){}

void TaskScheduler::createTask(uint8_t idTask, String name, uint16_t delay, void (*theTask)())
{
    taskData[idTask].idTask = idTask;
    taskData[idTask].name = name;
    taskData[idTask].delay = delay;
    taskData[idTask].theTask = theTask;
    iterationTask++;
}

void TaskScheduler::runTask(uint8_t idTask)
{
    if(millis() - taskData[idTask].prevMillis > taskData[idTask].delay)
    {
        void (*theTask)() = reinterpret_cast<void (*)(void)>(taskData[idTask].theTask);
        theTask();
        taskData[idTask].prevMillis = millis();
    }  
}