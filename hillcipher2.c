#include <stdio.h>

#define ALPHABET_SIZE 26

// Function to find the modular multiplicative inverse of a number
int modInverse(int a, int m) {
    a = a % m;
    int x;
    for ( x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1;
}

// Function to calculate the determinant of a 2x2 matrix
int determinant(int key[2][2]) {
    return key[0][0] * key[1][1] - key[0][1] * key[1][0];
}

// Function to calculate the inverse of a 2x2 matrix
void inverseMatrix(int key[2][2], int det, int inv_det) {
    int temp = key[0][0];
    key[0][0] = key[1][1];
    key[1][1] = temp;

    key[0][1] = -key[0][1];
    key[1][0] = -key[1][0];
    int i ,j;
    for ( i = 0; i < 2; i++)
        for ( j = 0; j < 2; j++)
            key[i][j] = (key[i][j] * inv_det) % ALPHABET_SIZE;
}

// Function to decrypt the ciphertext given plaintext-ciphertext pairs
void decryptKnownPlaintext(int plain1, int plain2, int cipher1, int cipher2) {
    int key[2][2] = {{plain1, plain2}, {cipher1, cipher2}};
    int det = determinant(key);
    int inv_det = modInverse(det, ALPHABET_SIZE);
    inverseMatrix(key, det, inv_det);

    printf("Recovered Key Matrix:\n");
    printf("%d %d\n", key[0][0], key[0][1]);
    printf("%d %d\n", key[1][0], key[1][1]);
}

int main() {
    // Suppose we have two plaintext-ciphertext pairs
    int plain1 = 4, plain2 = 9; // Corresponding to 'e' and 'j'
    int cipher1 = 16, cipher2 = 6; // Corresponding to 'q' and 'g'

    printf("Performing Known Plaintext Attack...\n");
    decryptKnownPlaintext(plain1, plain2, cipher1, cipher2);

    return 0;
}

