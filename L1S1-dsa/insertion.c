#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int* num = malloc(16*sizeof(int));

    for (int i = 0; i < 16;i++)
    {
        num[i] = i;

    }

    int *newPtr = realloc(num, sizeof(int)*20);

    for (int i = 16; i < 26; i++)
    {
        num[i] = i;
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%d\n", num[i]);
    }
    
    free(newPtr);
    

    // int* num1 = calloc(1000, sizeof(int));

    // for (int i = 0; i < 1000; i++)
    // {
    //     printf("%d", num1[i]);
    // }
    

    // free(num1); 
}






