#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "files.h"
#include "task.h"
#include "list.h"
#include "schedulers.h"

#define BUFFER_SIZE 100

int main() {
    FILE* file = fopen("rr-schedule_pri.txt", "r");

    if(file == NULL) {
        printf("Error while reading file.\n");
        return 1;
    }

    addTasksFromFile(file, BUFFER_SIZE);
    fclose(file);

    schedule();
    return 0;
}
