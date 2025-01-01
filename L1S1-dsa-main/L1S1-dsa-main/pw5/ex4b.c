#include <stdio.h>
#include <string.h>
// Reversing a String Array
void reverseString(char str[], int n)
{
    char temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    int n = strlen(str);
    reverseString(str, n);
    printf("Reversed string: %s\n", str);

    return 0;
}
