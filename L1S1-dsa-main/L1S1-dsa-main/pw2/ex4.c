#include <stdio.h>
int main()
{
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);

    if (ch >= '0' && ch <= '9')
    {
        printf("The character '%c' is a number.\n", ch);
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        printf("The character '%c' is a lowercase letter.\n", ch);
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        printf("The character '%c' is an uppercase letter.\n", ch);
    }
    else
    {
        printf("The character '%c' is neither a number nor a letter.\n", ch);
    }

    return 0;
}
