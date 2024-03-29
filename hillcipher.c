#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Function to encrypt the message using the Hill cipher
void encryptHill(char message[], int key[2][2]) {
    int len = strlen(message);
    int i, j;

    // Ensure the message length is even
    if (len % 2 != 0) {
        strcat(message, "X"); // Pad with 'X'
        len++;
    }

    // Encrypt the message
    for (i = 0; i < len; i += 2) {
        int char1 = message[i] - 'a';
        int char2 = message[i + 1] - 'a';

        int enc_char1 = (key[0][0] * char1 + key[0][1] * char2) % ALPHABET_SIZE;
        int enc_char2 = (key[1][0] * char1 + key[1][1] * char2) % ALPHABET_SIZE;

        printf("%c%c ", enc_char1 + 'a', enc_char2 + 'a');
    }
}

int main() {
    char message[] = "meet me at the usual place at ten rather than eight oclock";
    int key[2][2] = {{9, 4}, {5, 7}};

    printf("Encrypted message: ");
    encryptHill(message, key);
    printf("\n");

    return 0;
}

