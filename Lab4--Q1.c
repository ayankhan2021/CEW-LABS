#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char email[50];
    char phoneNumber[20];
    struct Contact* next;
};

struct Contact* addContact(struct Contact* addressBook) {
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));

    printf("Enter name, email, and phone number (separated by spaces): ");
    scanf("%s %s %s", newContact->name, newContact->email, newContact->phoneNumber);

    newContact->next = addressBook;
    printf("Contact added successfully.\n");

    return newContact;
}

struct Contact* deleteContact(struct Contact* addressBook) {
    if (addressBook == NULL) {
        printf("Address book is empty. No contacts to delete.\n");
        return NULL;
    }

    printf("Current address book:\n");
    int index = 1;
    struct Contact* current = addressBook;
    while (current != NULL) {
        printf("%d. Name: %s, Email: %s, Phone: %s\n", index,
               current->name, current->email, current->phoneNumber);
        current = current->next;
        index++;
    }

    printf("Enter the index of the contact to delete (1-%d): ", index - 1);
    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice >= index) {
        printf("Invalid index. Please enter a valid index.\n");
        return addressBook;
    }

    if (choice == 1) {
        struct Contact* temp = addressBook;
        addressBook = addressBook->next;
        free(temp);
    } else {
        struct Contact* prev = NULL;
        current = addressBook;
        for (int i = 1; i < choice; i++) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        free(current);
    }

    printf("Contact deleted successfully.\n");
    return addressBook;
}

void printContacts(struct Contact* addressBook) {
    if (addressBook == NULL) {
        printf("Address book is empty.\n");
        return;
    }

    printf("Current address book:\n");
    int index = 1;
    struct Contact* current = addressBook;
    while (current != NULL) {
        printf("%d. Name: %s, Email: %s, Phone: %s\n", index,
               current->name, current->email, current->phoneNumber);
        current = current->next;
        index++;
    }
}

void freeAddressBook(struct Contact* addressBook) {
    while (addressBook != NULL) {
        struct Contact* temp = addressBook;
        addressBook = addressBook->next;
        free(temp);
    }
}

int main() {
    struct Contact* addressBook = NULL;
    int choice;

    do {
        printf("\n--- Address Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Print Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addressBook = addContact(addressBook);
                break;
            case 2:
                addressBook = deleteContact(addressBook);
                break;
            case 3:
                printContacts(addressBook);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    freeAddressBook(addressBook);

    return 0;
}
