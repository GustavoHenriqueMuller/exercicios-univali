#include <stdio.h>

#include "schedulers.h"

// Add a task to the list
void add(Task* task) {
    insert(&TASKS_HEAD, task);
}

// Round robin scheduling
void schedule() {
    int currIndex = 0;

    while(1) {
        ListNode* currNode = getAt(TASKS_HEAD, currIndex);

        // Runs and adds to burst
        const int completed = run(currNode->task);

        // Process has ended maximum burst: delete
        if(completed) {
            printf("Deleted task = [%s]\n", currNode->task->name);
            delete(&TASKS_HEAD, currNode->task);
            currIndex--;
        }

        // Break if no elements left
        const int size = getSize(TASKS_HEAD);

        if(getSize(TASKS_HEAD) > 0) {
            currIndex = (currIndex + 1) % size;

            // Waits when re-executing list
            if(currIndex == 0) {
                Sleep(1000);
                system("@cls||clear");
            }
        } else {
            break;
        }
    }
}
