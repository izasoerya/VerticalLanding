#include "Scheduler.h"

TaskScheduler::TaskScheduler(uint8_t idTask, String name, uint16_t delay, void (*theTask)())
{
    this -> idTask = idTask;
    this -> name = name;
    this -> delay = delay;
    this -> theTask = theTask;
}

void TaskScheduler::runTask(uint8_t idTask)
{
    if(millis() - prevMillis > delay)
    {
        void (*theTask)() = reinterpret_cast<void (*)(void)>(theTask);
        theTask();
        prevMillis = millis();
    }  
}