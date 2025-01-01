#include <stdio.h>

int main()
{
    char ch;
    printf("Enter a character: ");
    ch = getchar();
    switch (ch)
    {
    case '1':
        printf("one\n");
        break;
    case '2':
        printf("two\n");
        break;
    case '3':
        printf("three\n");
        break;
    default:
        printf("other character\n");
        break;
    }

    return 0;
}
