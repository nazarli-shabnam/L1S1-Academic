#include <stdio.h>
// i used isdigit() function here so:
#include <ctype.h>

int main()
{
    int count = 0;
    char ch;

    printf("Enter characters, press Enter to stop:\n");
    while ((ch = getchar()) != '\n')
    {
        if (isdigit(ch))
        {
            count++;
        }
    }
    printf("Number of digits: %d\n", count);
    return 0;
}

/*
                        Algorithm Steps:
Start.
Set count = 0.
Read a character ch.
Check if ch is a digit (0-9):
If Yes, increment count by 1 and go back to step 3.
If No, go to the next step.
Check if ch is a newline (\n):
If Yes, go to step 6.
If No, go back to step 3.
Print the value of count.
End.
*/