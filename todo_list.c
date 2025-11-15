#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Todo {
    char taskName[100];
    char dueDate[15];
    int isDone;
    struct Todo *nextTask;
} Todo;

Todo* readTasks(char *fileName);
void saveTasks(Todo *listHead, char *fileName);
void addTask(Todo **listHead, char *taskName, char *dueDate, int isDone);
void deleteTask(Todo **listHead, char *taskName);
void changeTaskStatus(Todo *listHead, char *taskName);
void listAllTasks(Todo *listHead);

int main() {
    Todo *listHead = readTasks("tasks.txt");
    int choice;
    char task[100], date[15];

    while (1) {
        printf("\nTo-Do List Manager\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. Mark Task as Done/Not Done\n");
        printf("4. View All Tasks\n");
        printf("5. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To handle newline after scanf

        if (choice == 1) {
            printf("Enter Task Name: ");
            fgets(task, 100, stdin);
            task[strcspn(task, "\n")] = 0; // Remove trailing newline
            printf("Enter Due Date (DD-MM-YYYY): ");
            fgets(date, 15, stdin);
            date[strcspn(date, "\n")] = 0;
            addTask(&listHead, task, date, 0);
        } else if (choice == 2) {
            printf("Enter Task Name to Delete: ");
            fgets(task, 100, stdin);
            task[strcspn(task, "\n")] = 0;
            deleteTask(&listHead, task);
        } else if (choice == 3) {
            printf("Enter Task Name to Change Status: ");
            fgets(task, 100, stdin);
            task[strcspn(task, "\n")] = 0;
            changeTaskStatus(listHead, task);
        } else if (choice == 4) {
            listAllTasks(listHead);
        } else if (choice == 5) {
            saveTasks(listHead, "tasks.txt");
            printf("Tasks Saved. Goodbye!\n");
            return 0;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
}

Todo* readTasks(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return NULL;
    }

    Todo *listHead = NULL;
    Todo *lastTask = NULL;

    while (!feof(file)) {
        Todo *newTask = (Todo*)malloc(sizeof(Todo));
        if (fscanf(file, "%99[^,],%14[^,],%d\n", newTask->taskName, newTask->dueDate, &newTask->isDone) != 3) {
            free(newTask);
            break;
        }
        newTask->nextTask = NULL;

        if (listHead == NULL) {
            listHead = newTask;
        } else {
            lastTask->nextTask = newTask;
        }
        lastTask = newTask;
    }
    fclose(file);
    return listHead;
}

void saveTasks(Todo *listHead, char *fileName) {
    FILE *file = fopen(fileName, "w");
    Todo *current = listHead;

    while (current != NULL) {
        fprintf(file, "%s,%s,%d\n", current->taskName, current->dueDate, current->isDone);
        current = current->nextTask;
    }
    fclose(file);
}

void addTask(Todo **listHead, char *taskName, char *dueDate, int isDone) {
    Todo *newTask = (Todo*)malloc(sizeof(Todo));
    strcpy(newTask->taskName, taskName);
    strcpy(newTask->dueDate, dueDate);
    newTask->isDone = isDone;
    newTask->nextTask = NULL;

    if (*listHead == NULL) {
        *listHead = newTask;
    } else {
        Todo *current = *listHead;
        while (current->nextTask != NULL) {
            current = current->nextTask;
        }
        current->nextTask = newTask;
    }
    printf("Task Added Successfully.\n");
}

void deleteTask(Todo **listHead, char *taskName) {
    Todo *current = *listHead;
    Todo *previous = NULL;

    while (current != NULL && strcmp(current->taskName, taskName) != 0) {
        previous = current;
        current = current->nextTask;
    }

    if (current == NULL) {
        printf("Task Not Found.\n");
        return;
    }

    if (previous == NULL) {
        *listHead = current->nextTask;
    } else {
        previous->nextTask = current->nextTask;
    }
    free(current);
    printf("Task Deleted.\n");
}

void changeTaskStatus(Todo *listHead, char *taskName) {
    Todo *current = listHead;

    while (current != NULL) {
        if (strcmp(current->taskName, taskName) == 0) {
            current->isDone = !current->isDone;
            printf("Task Status Updated to %s.\n", current->isDone ? "Done" : "Not Done");
            return;
        }
        current = current->nextTask;
    }
    printf("Task Not Found.\n");
}

void listAllTasks(Todo *listHead) {
    Todo *current = listHead;

    if (current == NULL) {
        printf("No Tasks Available.\n");
        return;
    }

    printf("\nYour Tasks:\n");
    while (current != NULL) {
        printf("Task: %s, Due Date: %s, Status: %s\n",
               current->taskName, current->dueDate, current->isDone ? "Done" : "Not Done");
        current = current->nextTask;
    }
}