#ifndef CPU_H
#define CPU_H

#include "task.h"

#define QUANTUM 15
#define UNIT_TIME_SCALE 10 // Scale of unit-time (10ms)

int run(Task* task);

#endif // CPU_H
