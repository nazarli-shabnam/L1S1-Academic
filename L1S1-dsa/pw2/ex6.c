// Write a C program to find the smallest of three numbers:
// 1. Ask the user to enter the numbers
// 2. Search for the smallest number,
// 3. Display it.

// Add to your program:
//  1. Display the sum of the three numbers
//  2. Find and display the largest of three numbers

#include <stdio.h>

int main()
{
    int num1, num2, num3;
    printf("Enter 3 numbers: \n");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 < num2 && num1 < num3)
    {
        printf("The smallest number is %d\n", num1);
        if (num2 > num3)
        {
            printf("The largest number is %d\n", num2);
        }
        else
        {
            printf("The largest number is %d\n", num3);
        }
    }
    else if (num2 < num1 && num2 < num3)
    {
        printf("The smallest number is %d\n", num2);
        if (num1 > num3)
        {
            printf("The largest number is %d\n", num1);
        }
        else
        {
            printf("The largest number is %d\n", num3);
        }
    }
    else
    {
        printf("The smallest number is %d\n", num3);
        if (num1 > num2)
        {
            printf("The largest number is %d\n", num1);
        }
        else
        {
            printf("The largest number is %d\n", num2);
        }
    }
    printf("The sum of the three numbers is %d\n", num1 + num2 + num3);

    return 0;
}