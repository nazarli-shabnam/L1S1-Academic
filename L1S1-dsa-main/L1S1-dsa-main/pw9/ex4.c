#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int num;
    struct node* next;
};
int create(struct node** head) {
    int n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->num = data;
        newNode->next = *head;
        *head = newNode;
    }

    return n;
}

bool palin_check(struct node* head, int count) {
    int arr[count], i = 0;
    struct node* current = head;

    while (current != NULL) {
        arr[i++] = current->num;
        current = current->next;
    }

    for (int j = 0; j < count / 2; j++) {
        if (arr[j] != arr[count - j - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    struct node* p = NULL;
    int result, count;

    printf("Enter data into the list\n");
    count = create(&p);
    result = palin_check(p, count);

    if (result) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}
