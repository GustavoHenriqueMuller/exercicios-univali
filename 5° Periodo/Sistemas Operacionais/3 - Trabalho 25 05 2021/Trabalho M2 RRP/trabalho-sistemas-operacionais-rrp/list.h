#ifndef LIST_H
#define LIST_H

#include "task.h"

typedef struct node {
    Task* task;
    struct node* next;
} ListNode;

void insert(ListNode** head, Task* task);
void delete(ListNode** head, Task* task);
void traverse(ListNode* head);
ListNode* getEnd(ListNode* head);
ListNode* getAt(ListNode* head, int i);
int getSize(ListNode* head);
ListNode* getTaskWithMostPriority(ListNode* head);

#endif // LIST_H
