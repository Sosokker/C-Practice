#include <stdio.h>
#include <stdlib.h>
#include "tasks.h"

void loadTasksFromFile(struct Task tasks[], int *numTasks) {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("No tasks file found.\n");
        return;
    }

    int i = 0;
    while (fscanf(file, "%49s %99s %19s %d", tasks[i].title, tasks[i].description, tasks[i].dueDate, &tasks[i].completed) == 4) {
        i++;
        if (i >= MAX_TASKS) {
            break;
        }
    }

    *numTasks = i;

    fclose(file);
}

void saveTasksToFile(struct Task tasks[], int numTasks) {
    FILE *file = fopen("tasks.txt", "w");
    if (file == NULL) {
        printf("Error saving tasks.\n");
        return;
    }

    for (int i = 0; i < numTasks; i++) {
        fprintf(file, "%s %s %s %d\n", tasks[i].title, tasks[i].description, tasks[i].dueDate, tasks[i].completed);
    }

    fclose(file);
}

void addTask(struct Task tasks[], int *numTasks) {
    if (*numTasks >= MAX_TASKS) {
        printf("Maximum number of tasks reached.\n");
        return;
    }

    printf("Enter task title: ");
    scanf("%s", tasks[*numTasks].title);

    printf("Enter task description: ");
    scanf("%s", tasks[*numTasks].description);

    printf("Enter due date: ");
    scanf("%s", tasks[*numTasks].dueDate);

    tasks[*numTasks].completed = 0;

    (*numTasks)++;
}

void viewTasks(struct Task tasks[], int numTasks) {
    if (numTasks == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("Tasks:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("Task %d:\n", i + 1);
        printf("Title: %s\n", tasks[i].title);
        printf("Description: %s\n", tasks[i].description);
        printf("Due Date: %s\n", tasks[i].dueDate);
        printf("Status: %s\n", tasks[i].completed ? "Completed" : "Incomplete");
        printf("\n");
    }
}

void markCompleted(struct Task tasks[], int numTasks) {
    if (numTasks == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("Enter task number to mark as completed: ");
    int taskNum;
    scanf("%d", &taskNum);

    if (taskNum < 1 || taskNum > numTasks) {
        printf("Invalid task number.\n");
        return;
    }

    tasks[taskNum - 1].completed = 1;
}
