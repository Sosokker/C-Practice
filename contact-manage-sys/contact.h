#ifndef CONTACT_H
#define CONTACT_H

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

void addContact(Contact contacts[], int *numContacts);
void displayContacts(Contact contacts[], int numContacts);
void searchContacts(Contact contacts[], int numContacts, char *searchTerm);
void updateContact(Contact contacts[], int numContacts, char *searchTerm);
void deleteContact(Contact contacts[], int *numContacts, char *searchTerm);

#endif
