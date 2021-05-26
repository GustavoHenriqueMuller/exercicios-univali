#ifndef SCHEDULERS_H
#define SCHEDULERS_H

#include "CPU.h"
#include "list.h"

ListNode* TASKS_HEAD;

void add(Task* task);
void schedule();

#endif // SCHEDULERS_H
