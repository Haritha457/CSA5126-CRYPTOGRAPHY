#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLS 5

// Function to find the position of a character in the Playfair matrix
void findPosition(char matrix[ROWS][COLS], char ch, int *row, int *col) {
    if (ch == 'J' || ch == 'j') // Replacing 'J' with 'I' for simplicity
        ch = 'I';
    for (*row = 0; *row < ROWS; (*row)++) {
        for (*col = 0; *col < COLS; (*col)++) {
            if (matrix[*row][*col] == ch)
                return;
        }
    }
}

// Function to encrypt the Playfair cipher
void encryptPlayfair(char message[], char matrix[ROWS][COLS]) {
    int i;
    int row1, col1, row2, col2;
    for (i = 0; i < strlen(message); i += 2) {
        // Find positions of two characters in the matrix
        findPosition(matrix, message[i], &row1, &col1);
        findPosition(matrix, message[i + 1], &row2, &col2);

        // Encryption logic
        if (row1 == row2) {
            printf("%c%c", matrix[row1][(col1 + 1) % COLS], matrix[row2][(col2 + 1) % COLS]);
        } else if (col1 == col2) {
            printf("%c%c", matrix[(row1 + 1) % ROWS][col1], matrix[(row2 + 1) % ROWS][col2]);
        } else {
            printf("%c%c", matrix[row1][col2], matrix[row2][col1]);
        }
    }
}

int main() {
    char matrix[ROWS][COLS] = {
        {'M', 'F', 'H', 'I', 'K'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };
    char message[] = "Must see you over Cadogan West. Coming at once.";

    printf("Encrypted message: ");
    encryptPlayfair(message, matrix);
    printf("\n");

    return 0;
}

