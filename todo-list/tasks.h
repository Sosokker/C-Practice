#ifndef TASKS_H
#define TASKS_H

#define MAX_TITLE_LENGTH 50
#define MAX_DESC_LENGTH 100
#define MAX_TASKS 100

struct Task {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESC_LENGTH];
    char dueDate[20];
    int completed;
};

void loadTasksFromFile(struct Task tasks[], int *numTasks);
void saveTasksToFile(struct Task tasks[], int numTasks);
void addTask(struct Task tasks[], int *numTasks);
void viewTasks(struct Task tasks[], int numTasks);
void markCompleted(struct Task tasks[], int numTasks);

#endif
