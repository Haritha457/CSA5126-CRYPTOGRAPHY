#include <stdio.h>
#include <string.h>
#include <ctype.h>
char encryptChar(char plaintext, char key) {
    if (!isalpha(plaintext))
        return plaintext;
    char base = isupper(plaintext) ? 'A' : 'a'; 
    return ((plaintext - base + key) % 26) + base; 
}
void encryptText(char *plaintext, char *key) {
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);
    int i, j = 0;
    for (i = 0; i < plaintext_len; ++i) {
        if (isalpha(plaintext[i])) {
            plaintext[i] = encryptChar(plaintext[i], key[j % key_len] - 'a'); 
            ++j;
        }
    }
}
int main() {
    char plaintext[100], key[100];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';
    encryptText(plaintext, key);
    printf("Encrypted text: %s\n", plaintext);
    return 0;
}

