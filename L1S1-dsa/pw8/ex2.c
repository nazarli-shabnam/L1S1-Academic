/*
Write a SortedMerge() function that takes two lists, each of which is sorted in
increasing order, and merges the two together into one list which is in increasing order.
SortedMerge() should return the new list.
*/
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

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* a = NULL;
    struct Node* b = NULL;
    struct Node* result = NULL;

    push(&a, 10);
    push(&a, 5);
    push(&a, 2);

    push(&b, 9);
    push(&b, 6);
    push(&b, 3);

    printf("List A: ");
    printList(a);

    printf("List B: ");
    printList(b);

    result = sortedMerge(a, b);

    printf("Merged List: ");
    printList(result);

    return 0;
}
