#include <stdio.h>

int main() {
    unsigned long long l; // Original message length in bits
    unsigned long long totalLength;
    int k;

    // Input the original message length in bits
    printf("Enter the message length in bits: ");
    scanf("%llu", &l);

    // Calculate k
    // The total length = message length + 1 bit + k bits + 64 bits for the length
    // This total length should be a multiple of 512 bits
    totalLength = l + 1; // Add the '1' bit
    k = 0;

    // We add k number of '0' bits so that (totalLength + k) is congruent to 448 mod 512.
    // 448 bits are used because 448 + 64 (for the bit length) = 512 bits.
    while ((totalLength + k) % 512 != 448) {
        k++;
    }

    printf("The value of k is: %d\n", k);

    return 0;
}
