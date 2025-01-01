#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void findMinMax(struct Node* head, int* min, int* max) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    *min = head->data;
    *max = head->data;
    
    struct Node* current = head;
    while (current != NULL) {
        if (current->data < *min) {
            *min = current->data;
        }
        if (current->data > *max) {
            *max = current->data;
        }
        current = current->next;
    }
}

int main() {
    struct Node *head = NULL, *tail = NULL;
    int n, data, min, max;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    findMinMax(head, &min, &max);
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}
