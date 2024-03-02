#include <stdio.h>

// Function to calculate factorial
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int num_chars = 25; // Number of unique characters
    long long total_keys = factorial(num_chars); // Total keys without considering duplicates
    printf("Total possible keys (without considering duplicates): %lld\n", total_keys);

    // Considering some keys might produce identical encryption results
    long long effective_keys = 1;
    for (int i = 0; i < num_chars; i++) {
        effective_keys *= (num_chars - i);
    }
    printf("Effective unique keys (considering duplicates): %lld\n", effective_keys);

    return 0;
}

