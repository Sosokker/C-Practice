// File : contact.c
// Description : Implement functions defined in contact.h

#include <stdio.h>
#include <string.h>
#include "contact.h"

void addContact(Contact contacts[], int *numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }

    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, MAX_NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0';

    printf("Enter phone number: ");
    fgets(newContact.phone, MAX_PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';

    printf("Enter email address: ");
    fgets(newContact.email, MAX_EMAIL_LENGTH, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0';

    contacts[*numContacts] = newContact;
    (*numContacts)++;
    printf("Contact added successfully.\n");
}

void displayContacts(Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Contact list is empty.\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
        printf("--------------------\n");
    }
}

void searchContacts(Contact contacts[], int numContacts, char *searchTerm) {
    if (numContacts == 0) {
        printf("Contact list is empty.\n");
        return;
    }

    printf("Search results for '%s':\n", searchTerm);
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strstr(contacts[i].name, searchTerm) != NULL ||
            strstr(contacts[i].phone, searchTerm) != NULL ||
            strstr(contacts[i].email, searchTerm) != NULL) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            printf("--------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No matching contacts found.\n");
    }
}

void updateContact(Contact contacts[], int numContacts, char *searchTerm) {
    if (numContacts == 0) {
        printf("Contact list is empty.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strstr(contacts[i].name, searchTerm) != NULL ||
            strstr(contacts[i].phone, searchTerm) != NULL ||
            strstr(contacts[i].email, searchTerm) != NULL) {
            printf("Contact found. Enter new details:\n");

            printf("Enter name: ");
            fgets(contacts[i].name, MAX_NAME_LENGTH, stdin);
            contacts[i].name[strcspn(contacts[i].name, "\n")] = '\0';

            printf("Enter phone number: ");
            fgets(contacts[i].phone, MAX_PHONE_LENGTH, stdin);
            contacts[i].phone[strcspn(contacts[i].phone, "\n")] = '\0';

            printf("Enter email address: ");
            fgets(contacts[i].email, MAX_EMAIL_LENGTH, stdin);
            contacts[i].email[strcspn(contacts[i].email, "\n")] = '\0';

            printf("Contact updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No matching contacts found.\n");
    }
}

void deleteContact(Contact contacts[], int *numContacts, char *searchTerm) {
    if (numContacts == 0) {
        printf("Contact list is empty.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < *numContacts; i++) {
        if (strstr(contacts[i].name, searchTerm) != NULL ||
            strstr(contacts[i].phone, searchTerm) != NULL ||
            strstr(contacts[i].email, searchTerm) != NULL) {
            for (int j = i; j < *numContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*numContacts)--;
            printf("Contact deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No matching contacts found.\n");
    }
}
