#include "files.h"

// Parses file for tasks
void addTasksFromFile(FILE* file, int bufferSize) {
    char* currentLine;
    char buffer[bufferSize];

    while(fgets(buffer, bufferSize, file) != NULL) {
        Task* newTask = malloc(sizeof(Task));
        currentLine = strdup(buffer);

        // Initializes task
        newTask->name = strdup(strtok(currentLine, ","));
        newTask->priority = atoi(strtok(NULL, ","));
        newTask->maxBurst = atoi(strtok(NULL, ","));
        newTask->burst = newTask->maxBurst;

        // Add the task to the scheduler's list of tasks
        add(newTask);

        // Frees copy of buffer
        free(currentLine);
    }
}
