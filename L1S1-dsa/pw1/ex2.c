#include <stdio.h>
#include <math.h>

// Exercise 2: Write the algorithm that calculates the roots of a polynomial of degree 2. Write
// the flow chart and test it.

void calculate_roots(float a, float b, float c)
{
    float d = b * b - 4 * a * c;
    if (d < 0)
    {
        printf("No real roots\n");
    }
    else
    {
        float x1 = (-b + sqrt(d)) / (2 * a);
        float x2 = (-b - sqrt(d)) / (2 * a);
        printf("The roots are: x1 = %f, x2 = %f\n", x1, x2);
    }
}

int main()
{
    float a, b, c;
    printf("Enter the coefficients a, b, and c: ");
    scanf("%f %f %f", &a, &b, &c);
    calculate_roots(a, b, c);
    return 0;
}

// Algorithm

/*
Start

Input: Read coefficients a, b, and c.
Calculate Discriminant:
    calculate D=b^2 -4ac
Check Discriminant:
If D>0:
Calculate two real and distinct roots:
    x1 = (-b + squareroot(D))/2a
    x2 = (-b - squareroot(D))/2a
    print x1 and x2
else if D=0:
Calculate one real root:
    x = -b/2a
    print x
else if D<0:
    print "No real roots"

End
*/

/*
Testing
1)
input: 
a=1; b=-3;c=2
output:
Roots are real and different.
Root 1 = 2.00
Root 2 = 1.00
2)
input:
a=1;b=-2;c=1
output:
Root is real and repeated.
Root 1 = Root 2 = 1.00

*/