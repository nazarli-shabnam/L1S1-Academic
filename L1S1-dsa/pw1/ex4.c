#include <stdio.h>

/*
Exercise 4: Write an algorithm, a flow chart (and a C program) to:
Calculate the average of n grades entered by the your professor (to facilitate, choose grades
between 0 and 10);
 So if the obtained number is between 0 and 5, display a message to say that it is “low
average”;
 if the number is between 5 and 8, you display that it is “good average” ;
 and if the number is greater than 8, you display that it is “excellent average” ;
Test your algorithm/flow chart by hand before writing your C code
*/

int main()
{
    int n;
    float grade, sum = 0.0, average;

    printf("Enter the number of grades: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter grade %d (between 0 and 10): ", i + 1);
        scanf("%f", &grade);

        while (grade < 0 || grade > 10)
        {
            printf("Invalid grade! Please enter a grade between 0 and 10: ");
            scanf("%f", &grade);
        }

        sum += grade;
    }

    average = sum / n;

    printf("Average: %.2f\n", average);
    if (average >= 0 && average < 5)
    {
        printf("Low average\n");
    }
    else if (average >= 5 && average < 8)
    {
        printf("Good average\n");
    }
    else if (average >= 8 && average <= 10)
    {
        printf("Excellent average\n");
    }
    else
    {
        printf("Error: Average out of expected range\n");
    }

    return 0;
}


//Algorithm

/*
Start.

1.Input the number of grades n from the user.
2.Initialize sum = 0.
4.3For each grade (from 1 to n):
5.Input the grade.
6.Add the grade to sum.
7.Calculate the average: average = sum / n.
8.If average is between 0 and 5 (inclusive), display "low average".
9.If average is between 5 and 8 (exclusive), display "good average".
10.If average is greater than or equal to 8, display "excellent average".


End.
*/
                                //Testing
/*
Input: 3 grades: 4, 6, 9.
Output: "Good average" since the average is (4 + 6 + 9) / 3 = 6.33.

Input: 5 grades: 3, 2, 4, 5, 1.
Output: "Low average" since the average is (3 + 2 + 4 + 5 + 1) / 5 = 3.0.

Input: 2 grades: 9, 10.
Output: "Excellent average" since the average is (9 + 10) / 2 = 9.5
*/


/*
                                Flow Chart
Start (Oval)

    Input number of grades (n) (Parallelogram)
    Initialize sum to 0.0 (Rectangle)

    Loop for each grade (i = 0 to n-1) (Rectangle)


    Input grade i+1 (Parallelogram)
    The program prompts the user to input a grade between 0 and 10.
    Is the grade valid (0 ≤ grade ≤ 10)? (Diamond)
    If the grade is within the valid range, proceed.
    If not, prompt the user to re-enter the grade.
    Add grade to sum (Rectangle)
    The valid grade is added to the total sum.
    End Loop (Once all grades are entered)

    Calculate average = sum / n (Rectangle)

    The program calculates the average of the grades.
    Display average (Parallelogram)

    The program prints the average.
    Is average < 5? (Diamond)

    If Yes: Display "Low average" (Parallelogram)
    If No, proceed.
    Is average between 5 and 8? (Diamond)

    If Yes: Display "Good average" (Parallelogram)
    If No, proceed.
    Is average between 8 and 10? (Diamond)

    If Yes: Display "Excellent average" (Parallelogram)
    If No, proceed.
    Display "Error: Average out of expected range" (Parallelogram)

    If none of the conditions are satisfied, display an error message.
End (Oval)
*/




