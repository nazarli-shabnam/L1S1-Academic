#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
bool isPalindrome(struct Node* head) {
    if (head == NULL) return true;

    struct Node* left = head;
    struct Node* right = head;
    while (right->next != NULL) {
        right = right->next;
    }
    while (left != NULL && right != NULL && left != right && right->next != left) {
        if (left->data != right->data) {
            return false;
        }
        left = left->next;
        right = right->prev;
    }

    return true;
}

int main() {
    struct Node *head = NULL, *tail = NULL;
    int n;
    char data;

    printf("Enter the number of characters: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter character for node %d: ", i + 1);
        scanf(" %c", &data);
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

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}
