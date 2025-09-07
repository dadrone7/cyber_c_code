#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWER   "abcdefghijklmnopqrstuvwxyz"
#define DIGITS  "0123456789"
#define SYMBOLS "!@#$%^&*()-_=+[]{};:,.<>?/\\|~`"
#define CHARSET UPPER LOWER DIGITS SYMBOLS

void generatePassword(int length) {
    const char charset[] = CHARSET;
    int charsetLength = sizeof(charset) - 1;

    char password[length + 1]; // +1 for null terminator
    for (int i = 0; i < length; i++) {
        int index = rand() % charsetLength;
        password[i] = charset[index];
    }
    password[length] = '\0'; // Null-terminate the string

    printf("Generated Password: %s\n", password);
}

int main() {
    int length;

    printf("Enter desired password length: ");
    scanf("%d", &length);

    if (length < 4) {
        printf("Password length should be at least 4 for decent security.\n");
        return 1;
    }

    srand(time(NULL)); // Seed the random number generator
    generatePassword(length);

    return 0;
}
