#ifndef TASK_H
#define TASK_H

typedef struct task {
    char* name;
    int priority;
    int burst;
    int maxBurst;
} Task;

#endif // TASK_H
