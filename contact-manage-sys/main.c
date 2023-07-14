#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "utils.h"

int main() {
    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;
    char searchTerm[MAX_NAME_LENGTH];

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                printf("Enter search term: ");
                fgets(searchTerm, MAX_NAME_LENGTH, stdin);
                searchTerm[strcspn(searchTerm, "\n")] = '\0';
                searchContacts(contacts, numContacts, searchTerm);
                break;
            case 4:
                printf("Enter search term: ");
                fgets(searchTerm, MAX_NAME_LENGTH, stdin);
                searchTerm[strcspn(searchTerm, "\n")] = '\0';
                updateContact(contacts, numContacts, searchTerm);
                break;
            case 5:
                printf("Enter search term: ");
                fgets(searchTerm, MAX_NAME_LENGTH, stdin);
                searchTerm[strcspn(searchTerm, "\n")] = '\0';
                deleteContact(contacts, &numContacts, searchTerm);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
