#include <stdio.h>

// Exercise 1: Write the algorithm that compares two numbers and returns the greater. Write the
//  flow chart and test it

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    printf("Enter 2 numbers to compare\n");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("The greater number is %d", max(a, b));

    return 0;
}

// Algorithm

/*
1. Start

 Input: Read two numbers, num1 and num2.
2. Compare the Numbers:
 If num1 is greater than num2, then:
.Print num1 is greater.
Else if num2 is greater than num1, then:
Print num2 is greater.
Else:
Print "Both numbers are equal."

End
*/

/*
Testing

Input: num1 = 5, num2 = 10
Output: "The greater number is: 10"

Input: num1 = -3, num2 = -1
Output: "The greater number is: -1"

Input: num1 = 7, num2 = 7
Output: "Both numbers are equal."
*/