#include <stdio.h>

int converter()
{
    printf("Enter seconds:/n");
    int seconds;
    scanf("%d", seconds);
    printf("It is %d minutes and %d seconds\n", seconds / 60, seconds % 60);
}
int main()
{
    converter();
    return 0;
}
