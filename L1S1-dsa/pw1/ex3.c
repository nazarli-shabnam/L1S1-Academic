#include <stdio.h>
#include <stdlib.h>
// Exercise 3: Write an algorithm, a flow chart (and a C program) that controls the number
// entered by the user:
//  So if the number is negative, you discard the program;
//  if the number is between 1 and 100, you display it ;
//  and if the number is greater than 100, you ask user to enter another one between 1 and
// 100.
// Test it!

int control(int *num)
{
    if (*num < 0)
    {
        exit(0);
    }
    else if (*num < 100)
    {
        printf("The number is %d\n", *num);
    }
    else if (*num > 100)
    {
        while (*num > 100)
        {
            printf("Enter another number between 1 and 100: ");
            scanf("%d", num);
        }
    }
}
int main()
{
    printf("Enter a number: ");
    int userNum;
    scanf("%d", &userNum);
    control(&userNum);

    return 0;
}

/*
                        Algorithm
Start
    Prompt the user to enter a number.
    Check if the number is negative:
        If yes, terminate the program.
    If the number is between 1 and 100 (inclusive):
        Display the number.
    If the number is greater than 100:
        Keep asking the user to enter a number between 1 and 100 until a valid number is entered.
End
*/

/*                       Testing
--Input: -5
Output: "The number is negative. Program terminated."

--Input: 50
Output: "You entered: 50"

--Input: 150 → 90
Output: "Number is greater than 100. Please enter a number between 1 and 100: You entered: 90"

*/

/*                        Flow chart

Start (Oval)

Input a number (Parallelogram)

Is the number negative? (Diamond)

If the number is less than 0:
    Exit program (Oval)
If No, proceed to the next step.

Is the number between 1 and 100? (Diamond)

If Yes:
    Display the number (Parallelogram)
If No, proceed to the next step.

Is the number greater than 100? (Diamond)

If Yes:
    While the number is greater than 100 (Loop/Rectangle)
    Input a number between 1 and 100 (Parallelogram)
    The user is prompted to input another number until it falls between 1 and 100.
End (Oval)
*/