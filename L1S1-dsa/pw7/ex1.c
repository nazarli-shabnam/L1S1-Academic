#include <stdio.h>
#define MAX 100

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

// initialize the stack
void initializeStack(Stack* stack) {
    stack->top = -1;
}

//stack is empty?
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

//stack is full?
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

//push an elementto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack->items[++stack->top] = value;
    printf("Pushed %d onto the stack.\n", value);
}

//pop an element from
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    return stack->items[stack->top--];
}

//display
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Popped: %d\n", pop(&stack));
    display(&stack);

    return 0;
}
