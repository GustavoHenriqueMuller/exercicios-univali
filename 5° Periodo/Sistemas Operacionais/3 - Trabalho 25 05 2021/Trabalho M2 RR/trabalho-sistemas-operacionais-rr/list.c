#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "task.h"

// Add a new task to the list of tasks
void insert(ListNode** head, Task* newTask) {
    // Add the new task to the list
    ListNode* newNode = malloc(sizeof(ListNode));
    newNode->task = newTask;
    newNode->next = NULL;

    if(*head == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        ListNode* end = getEnd(*head);
        end->next = newNode;
    }
}

// Delete the selected task from the list
void delete(ListNode** head, Task* task) {
    ListNode* temp;
    ListNode* prev;
    temp = *head;

    // Special case - beginning of list
    if (strcmp(task->name, temp->task->name) == 0) {
        *head = (*head)->next;
    } else {
        // Interior or last element in the list
        prev = *head;
        temp = temp->next;
        while (strcmp(task->name,temp->task->name) != 0) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
    }
}

// Traverse the list
void traverse(ListNode* head) {
    ListNode* temp;
    temp = head;

    while (temp != NULL) {
        printf("[%s] [%d] [%d/%d]\n", temp->task->name, temp->task->priority, temp->task->burst, temp->task->maxBurst);
        temp = temp->next;
    }
}

// Gets the end of the list
ListNode* getEnd(ListNode* head) {
    if(head != NULL) {
        ListNode* temp = head;

        while(1) {
            if(temp->next == NULL) {
                return temp;
            } else {
                temp = temp->next;
            }
        }
    }
}

// Gets task at position "i"
ListNode* getAt(ListNode* head, int i) {
    if(head != NULL) {
        int cont = 0;
        ListNode* temp = head;

        while(cont < i) {
            if(temp->next == NULL) {
                return NULL;
            } else {
                cont++;
                temp = temp->next;
            }
        }

        return temp;
    } else {
        return NULL;
    }
}

// Gets the size of list
int getSize(ListNode* head) {
    if(head != NULL) {
        int currSize = 1;
        ListNode* temp = head;

        while(1) {
            if(temp->next == NULL) {
                return currSize;
            } else {
                currSize++;
                temp = temp->next;
            }
        }
    } else {
        return 0;
    }
}
