#include <stdio.h>
#include "schedulers.h"

// Add a task to the list
void add(Task* task) {
    insert(&TASKS_HEAD, task);
}

// Round robin scheduling
void schedule() {
    while(getSize(TASKS_HEAD) > 0) {
        // Only check priority if more than one task is present
        ListNode* currNode = getSize(TASKS_HEAD) > 1 ? getTaskWithMostPriority(TASKS_HEAD) : getAt(TASKS_HEAD, 0);

        // Executes until completion
        while(run(currNode->task) == 0);

        // Deletes executed proccess
        printf("Deleted task = [%s]\n", currNode->task->name);
        delete(&TASKS_HEAD, currNode->task);

        // Waits when re-executing list
        Sleep(1000);
        system("@cls||clear");
    }
}
