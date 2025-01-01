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
    int length = 0, i;
    struct Node* temp = source;

/*************  ✨ Codeium Command ⭐  *************/
/**
 * Splits a linked list into two halves, where the second half is the larger if the list has an odd length.
 * @param source The list to be split.
 * @param front_ref The reference to the front half of the list.
 * @param back_ref The reference to the back half of the list.
 */
/******  61fc9475-37a7-46f3-8bae-904680d14e1b  *******/    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    int mid = (length + 1) / 2;

    temp = source;
    for (i = 1; i < mid; i++) {
        temp = temp->next;
    }

    *front_ref = source;
    *back_ref = temp->next;
    temp->next = NULL;
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
    struct Node* front = NULL;
    struct Node* back = NULL;

    push(&head, 8);
    push(&head, 11);
    push(&head, 3);
    push(&head, 4);
    push(&head, 1);

    printf("Original List: ");
    printList(head);

    frontBackSplit(head, &front, &back);

    printf("Front List: ");
    printList(front);

    printf("Back List: ");
    printList(back);

    return 0;
}
