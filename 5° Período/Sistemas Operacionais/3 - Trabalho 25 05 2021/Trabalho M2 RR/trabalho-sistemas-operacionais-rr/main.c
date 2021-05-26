#include <stdio.h>

#include "files.h"
#include "task.h"
#include "list.h"
#include "schedulers.h"

#define BUFFER_SIZE 100

int main() {
    // Gets file with tasks
    FILE* file = fopen("rr-schedule.txt", "r");
    if(file == NULL) {
        printf("Error while reading file.\n");
        return 1;
    }

    // Adds and executes tasks
    addTasksFromFile(file, BUFFER_SIZE);
    schedule();

    // Deallocates
    fclose(file);
    return 0;
}
