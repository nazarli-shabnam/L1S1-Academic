#include <stdio.h>
// Convert case of characters
char my_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 32;
    }
    return c;
}

char my_tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 32;
    }
    return c;
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%99s", str);

    printf("Uppercase: ");
    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", my_toupper(str[i]));
    }
    printf("\n");

    printf("Lowercase: ");
    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", my_tolower(str[i]));
    }
    printf("\n");

    return 0;
}
