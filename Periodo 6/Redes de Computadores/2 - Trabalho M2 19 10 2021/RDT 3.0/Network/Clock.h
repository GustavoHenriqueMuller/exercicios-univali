#ifndef RDT_CLOCK_H
#define RDT_CLOCK_H

#include <time.h>
#include <iostream>
#include <Windows.h>

clock_t CLOCK;

void delayClock(int seconds) {
    clock_t start = clock() + (1000 * (seconds + seconds * rand() % 2));
    while(clock() < start);
}

void startClock() {
    CLOCK = clock();
}

double stopClock() {
    return (clock() - CLOCK) / 1000;
}

#endif //RDT_CLOCK_H
