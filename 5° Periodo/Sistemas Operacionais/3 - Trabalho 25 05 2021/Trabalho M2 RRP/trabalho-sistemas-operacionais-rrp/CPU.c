#include <stdio.h>
#include <windows.h>

#include "CPU.h"
#include "task.h"

// Run this task for the specified time slice, returns 1 for completed
int run(Task* task) {
    // Subtract from burst
    const int executionUnits = (task->burst > QUANTUM) ? QUANTUM : task->burst;
    const int realTimeExecutionUnits = executionUnits * UNIT_TIME_SCALE;
    task->burst -= executionUnits;

    // Simulate execution
    printf("Running task = [%s] [%d] [%d/%d] for %d units (%dms).\n", task->name, task->priority, task->burst, task->maxBurst, executionUnits, realTimeExecutionUnits);
    Sleep(realTimeExecutionUnits);

    return task->burst == 0;
}
