#include <stdio.h>
#define MAX 100

typedef struct Stack
{
    int items[MAX];
    int top;
} Stack;
void initializeStack(Stack *stack)
{
    stack->top = -1;
}
void push(Stack *stack, int value)
{
    stack->items[++stack->top] = value;
}
int pop(Stack *stack)
{
    return stack->items[stack->top--];
}
int peek(Stack *stack)
{
    return stack->items[stack->top];
}
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}
void nextGreaterElement(int arr[], int n)
{
    Stack stack;
    initializeStack(&stack);
    int nge[MAX];

    for (int i = n - 1; i >= 0; i--)
    {
        while (!isEmpty(&stack) && peek(&stack) <= arr[i])
        {
            pop(&stack);
        }

        nge[i] = isEmpty(&stack) ? -1 : peek(&stack);
        push(&stack, arr[i]);
    }

    printf("Next Greater Elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nge[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {4, 12, 5, 3, 2, 5, 3, 1, 2, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreaterElement(arr, n);

    return 0;
}
