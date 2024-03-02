#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLS 5

// Function to find the position of a character in the Playfair matrix
void findPosition(char matrix[ROWS][COLS], char ch, int *row, int *col) {
    if (ch == 'J') // Replacing 'J' with 'I' for simplicity
        ch = 'I';
    for (*row = 0; *row < ROWS; (*row)++) {
        for (*col = 0; *col < COLS; (*col)++) {
            if (matrix[*row][*col] == ch)
                return;
        }
    }
}

// Function to decode the Playfair cipher
void decodePlayfair(char cipher[], char matrix[ROWS][COLS]) {
    int i;
    int row1, col1, row2, col2;
    for (i = 0; i < strlen(cipher); i += 2) {
        // Find positions of two characters in the matrix
        findPosition(matrix, cipher[i], &row1, &col1);
        findPosition(matrix, cipher[i + 1], &row2, &col2);

        // Decoding logic
        if (row1 == row2) {
            printf("%c%c", matrix[row1][(col1 - 1 + COLS) % COLS], matrix[row2][(col2 - 1 + COLS) % COLS]);
        } else if (col1 == col2) {
            printf("%c%c", matrix[(row1 - 1 + ROWS) % ROWS][col1], matrix[(row2 - 1 + ROWS) % ROWS][col2]);
        } else {
            printf("%c%c", matrix[row1][col2], matrix[row2][col1]);
        }
    }
}

int main() {
    char matrix[ROWS][COLS] = {
        {'K', 'X', 'J', 'E', 'Y'},
        {'U', 'R', 'E', 'B', 'Z'},
        {'W', 'H', 'R', 'Y', 'T'},
        {'U', 'H', 'E', 'Y', 'F'},
        {'S', 'K', 'R', 'E', 'H'}
    };
    char cipher[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHE";

    printf("Decoded message: ");
    decodePlayfair(cipher, matrix);
    printf("\n");

    return 0;
}

