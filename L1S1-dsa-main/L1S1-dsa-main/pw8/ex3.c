#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void frontBackSplit(struct Node* source, struct Node** front_ref, struct Node** back_ref) {
    struct Node* slow = source;
    struct Node* fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front_ref = source;
    *back_ref = slow->next;
    slow->next = NULL;
}

struct Node* sortedMerge(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct Node* result;

    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }

    return result;
}

void mergeSort(struct Node** head_ref) {
    struct Node* head = *head_ref;
    struct Node* a;
    struct Node* b;

    if (head == NULL || head->next == NULL) {
        return;
    }

    frontBackSplit(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *head_ref = sortedMerge(a, b);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    push(&head, 4);
    push(&head, 1);
    push(&head, 5);
    push(&head, 3);

    printf("Original List: ");
    printList(head);

    mergeSort(&head);

    printf("Sorted List: ");
    printList(head);

    return 0;
}
