#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define S 5

char M[S][S];

void generateMatrix(char k[]) {
    int i, j, l, f = 0, A[26] = {0};
    l = strlen(k);
    for (i = 0; i < l; ++i)
        if (k[i] != 'j')
            A[k[i] - 'a'] = 1;
    for (i = 0, l = 0; i < S; ++i)
        for (j = 0; j < S; ++j) {
            if (l < strlen(k)) {
                if (k[l] == 'j')
                    ++l;
                M[i][j] = toupper(k[l]);
                A[k[l] - 'a'] = 2;
                ++l;
            } else {
                while (A[f] == 2)
                    ++f;
                M[i][j] = f + 'A';
                A[f] = 2;
                ++f;
            }
        }
}

void encryptPair(char a, char b) {
    int i, j, x1, x2, y1, y2;
    for (i = 0; i < S; ++i)
        for (j = 0; j < S; ++j) {
            if (M[i][j] == a) {
                x1 = i;
                y1 = j;
            } else if (M[i][j] == b) {
                x2 = i;
                y2 = j;
            }
        }
    if (x1 == x2)
        printf("%c%c", M[x1][(y1 + 1) % S], M[x2][(y2 + 1) % S]);
    else if (y1 == y2)
        printf("%c%c", M[(x1 + 1) % S][y1], M[(x2 + 1) % S][y2]);
    else
        printf("%c%c", M[x1][y2], M[x2][y1]);
}

int main() {
    char k[50], t[100], c[100];
    int i, j = 0;
    printf("Enter the keyword (without 'j'): ");
    scanf("%s", k);
    generateMatrix(k);
    printf("Enter the plaintext: ");
    scanf("%s", t);
    for (i = 0; t[i] != '\0'; ++i)
        if (t[i] != 'j')
            c[j++] = toupper(t[i]);
    c[j] = '\0';
    printf("Encrypted text: ");
    for (i = 0; i < strlen(c); i += 2) {
        if (c[i + 1] == '\0')
            printf("%cX", c[i]);
        else if (c[i] == c[i + 1])
            printf("%cX", c[i]);
        else
            encryptPair(c[i], c[i + 1]);
    }
    return 0;
}

