//Sort a String in Alphabetical Order
/*
Exercise 4
Write a c program to find the next greater element (the first greater element on the
right side) in an array using Stack
*/
#include <stdio.h>
#include <string.h>

void sortString(char str[]) {
    int n = strlen(str);
    char temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    sortString(str);

    printf("String in alphabetical order: %s\n", str);
    return 0;
}
