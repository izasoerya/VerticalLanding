#include "Scheduler.h"

TaskScheduler::TaskScheduler(uint8_t idTask, String name, uint16_t delay, TaskFunction taskFunc)
{
    this -> idTask = idTask;
    this -> name = name;
    this -> delay = delay;
    this -> taskFunc = taskFunc;
}

void TaskScheduler::runTask()
{
    if(millis() - prevMillis > delay && !isSuspended)
    {
        taskFunc();
        prevMillis = millis();
    }  
}

void TaskScheduler::suspendTask()
{
    isSuspended = true;
}

void TaskScheduler::resumeTask()
{
    isSuspended = false;
}