#include <stdio.h>
#include "tasks.h"

int main() {
    int numTasks = 0;
    struct Task tasks[MAX_TASKS];

    loadTasksFromFile(tasks, &numTasks);

    int choice;
    do {
        printf("To-Do List Application\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Completed\n");
        printf("4. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(tasks, &numTasks);
                break;
            case 2:
                viewTasks(tasks, numTasks);
                break;
            case 3:
                markCompleted(tasks, numTasks);
                break;
            case 4:
                saveTasksToFile(tasks, numTasks);
                printf("Tasks saved. Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
