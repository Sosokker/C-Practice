#include <stdio.h>
#include "utils.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void printMenu() {
    printf("\nContact Management System\n");
    printf("1. Add contact\n");
    printf("2. Display all contacts\n");
    printf("3. Search contact\n");
    printf("4. Update contact\n");
    printf("5. Delete contact\n");
    printf("6. Exit\n");
}
