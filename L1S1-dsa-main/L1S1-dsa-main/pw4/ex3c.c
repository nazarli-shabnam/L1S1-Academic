/*
EXPLANATION OF CODE
*/

void swap(int *p, int *q);
int main(void)
{
    int a = 3, b = 7;
    printf("%d %d\n", a, b); // Print initial values of a and b
    swap(&a, &b);            // Call swap function, passing the addresses of a and b
    printf("%d %d\n", a, b); // Print swapped values of a and b
    return 0;
}

void swap(int *p, int *q)
{
    int tmp;
    tmp = *p; // Store the value of the variable pointed to by p (a) in tmp
    *p = *q;  // Assign the value of the variable pointed to by q (b) to *p (a)
    *q = tmp; // Assign the value of tmp (original a) to *q (b)
}
