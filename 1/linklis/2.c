#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct TaskNode {
    char description[100];
    bool completed;
    struct TaskNode *next;
} TaskNode;

TaskNode *head = NULL;

void addTask(const char *description) {
    TaskNode *newTask = malloc(sizeof(TaskNode));
    if (newTask != NULL) {
        strncpy(newTask->description, description, sizeof(newTask->description));
        newTask->completed = false;
        newTask->next = head;
        head = newTask;
    } else {
        printf("Failed to add task: out of memory.\n");
    }
}

void displayTasks() {
    printf("Task List:\n");
    TaskNode *current = head;
    int index = 1;
    while (current != NULL) {  
        printf("%d. [%s] %s\n", index++, current->completed ? "X" : " ", current->description);
        current = current->next;
    }
}

int main() {
    addTask("Finish report");
    addTask("Prepare presentation");
    displayTasks();
    return 0;
}
