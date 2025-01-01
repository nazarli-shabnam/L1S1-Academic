#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct Stack
{
    char items[MAX];
    int top;
} Stack;
void initializeStack(Stack *stack)
{
    stack->top = -1;
}
void push(Stack *stack, char value)
{
    stack->items[++stack->top] = value;
}
char pop(Stack *stack)
{
    return stack->items[stack->top--];
}
int isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
int isBalanced(char *expression)
{
    Stack stack;
    initializeStack(&stack);

    for (int i = 0; i < strlen(expression); i++)
    {
        char current = expression[i];

        if (current == '(' || current == '{' || current == '[')
        {
            push(&stack, current);
        }
        else if (current == ')' || current == '}' || current == ']')
        {
            if (stack.top == -1 || !isMatchingPair(pop(&stack), current))
            {
                return 0;
            }
        }
    }
    return stack.top == -1;
}

int main()
{
    char expression[MAX];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isBalanced(expression))
    {
        printf("Balanced\n");
    }
    else
    {
        printf("Not Balanced\n");
    }

    return 0;
}
