#include <stdio.h>
#include <string.h>
//(Pointers): String operations
int my_strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

char* my_strcat(char* dest, const char* src) {
    char* ptr = dest + strlen(dest);
    while (*src != '\0') {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}

char* my_strcpy(char* dest, const char* src) {
    char* ptr = dest;
    while (*src != '\0') {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}

int main() {
    char str1[100], str2[100], result[200];

    printf("Enter the first string: ");
    scanf("%99s", str1);
    printf("Enter the second string: ");
    scanf("%99s", str2);

    printf("Comparing strings: %s\n", my_strcmp(str1, str2) == 0 ? "Equal" : "Not Equal");

    my_strcpy(result, str1);
    my_strcat(result, str2);
    printf("Concatenated string: %s\n", result);

    my_strcpy(result, str2);
    printf("Copied string: %s\n", result);

    return 0;
}
