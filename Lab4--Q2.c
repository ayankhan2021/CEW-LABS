#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertNode(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
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

struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct Node* mergedList = NULL;
    struct Node* current = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            mergedList = insertNode(mergedList, list1->data);
            list1 = list1->next;
        } else {
            mergedList = insertNode(mergedList, list2->data);
            list2 = list2->next;
        }
    }

    while (list1 != NULL) {
        mergedList = insertNode(mergedList, list1->data);
        list1 = list1->next;
    }

    while (list2 != NULL) {
        mergedList = insertNode(mergedList, list2->data);
        list2 = list2->next;
    }

    return mergedList;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* list1 = NULL;
    list1 = insertNode(list1, 1);
    list1 = insertNode(list1, 3);
    list1 = insertNode(list1, 5);
    printf("List 1: ");
    printList(list1);

    struct Node* list2 = NULL;
    list2 = insertNode(list2, 2);
    list2 = insertNode(list2, 4);
    list2 = insertNode(list2, 6);
    printf("List 2: ");
    printList(list2);

    struct Node* mergedList = mergeSortedLists(list1, list2);
    printf("Merged List: ");
    printList(mergedList);

    freeList(list1);
    freeList(list2);
    freeList(mergedList);

    return 0;
}
