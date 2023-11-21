#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

struct Node* removeOddIndices(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    int index = 1;

    while (current != NULL) {
        if (index % 2 != 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }

            struct Node* temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }

        index++;
    }

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    for (int i = 1; i <= 6; i++) {
        head = insertNode(head, i);
    }

    printf("Original Linked List: ");
    printList(head);

    head = removeOddIndices(head);

    printf("Linked List after Removing Odd Indices: ");
    printList(head);

    // Free memory
    freeList(head);

    return 0;
}
