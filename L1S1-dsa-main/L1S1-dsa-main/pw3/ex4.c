#include <stdio.h>

int my_isalpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int my_isdigit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    char c;
    printf("Enter a character: ");
    scanf(" %c", &c);

    if (my_isalpha(c)) {
        printf("'%c' is a letter.\n", c);
    } else if (my_isdigit(c)) {
        printf("'%c' is a digit.\n", c);
    } else {
        printf("'%c' is neither a letter nor a digit.\n", c);
    }
    return 0;
}
