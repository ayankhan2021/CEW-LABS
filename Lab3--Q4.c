#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of a linked list
struct Node* insertNode(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to remove elements with odd indices from a linked list
struct Node* removeOddIndices(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    int index = 1;

    while (current != NULL) {
        if (index % 2 != 0) {
            // Remove the node with an odd index
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }

            struct Node* temp = current;
            current = current->next;
            free(temp);
        } else {
            // Move to the next node
            prev = current;
            current = current->next;
        }

        index++;
    }

    return head;
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory allocated for a linked list
void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    for (int i = 1; i <= 6; i++) {
        head = insertNode(head, i);
    }

    // Print the original linked list
    printf("Original Linked List: ");
    printList(head);

    // Remove elements with odd indices
    head = removeOddIndices(head);

    // Print the modified linked list
    printf("Linked List after Removing Odd Indices: ");
    printList(head);

    // Free memory
    freeList(head);

    return 0;
}
