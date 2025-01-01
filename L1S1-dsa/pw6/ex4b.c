#include <stdio.h>
#include <string.h>
// Display Unique Characters and Their Frequency

void characterFrequency(char str[]) {
    int freq[256] = {0};
    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        freq[(int)str[i]]++;
    }

    printf("Character frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", i, freq[i]);
        }
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    characterFrequency(str);
    return 0;
}
