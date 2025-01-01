#include <stdio.h>
// Recursive Approach
int gcd(int m, int n)
{
    if (n == 0)
        return m;
    return gcd(n, m % n);
}

int main()
{
    int m, n;
    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);

    printf("G.C.D of %d and %d is %d\n", m, n, gcd(m, n));
    return 0;
}
