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

int* convertLinkedListToArray(struct Node* head, int* size) {
    if (head == NULL) {
        *size = 0;
        return NULL;
    }

    *size = 0;
    struct Node* current = head;
    while (current != NULL) {
        (*size)++;
        current = current->next;
    }

    int* array = (int*)malloc(*size * sizeof(int));
    if (array == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    current = head;
    for (int i = 0; i < *size; i++) {
        array[i] = current->data;
        current = current->next;
    }

    return array;
}

void printArray(int* array, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
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

    for (int i = 1; i <= 5; i++) {
        head = insertNode(head, i);
    }

    int size;
    int* array = convertLinkedListToArray(head, &size);

    printf("Original Linked List: ");
    printArray(array, size);

    freeList(head);
    free(array);

    return 0;
}
