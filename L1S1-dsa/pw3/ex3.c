#include <stdio.h>

int my_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%99s", str);

    int length = my_strlen(str);
    printf("The length of the string is: %d\n", length);
    return 0;
}
