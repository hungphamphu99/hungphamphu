#include <stdio.h>

// Function to perform modular exponentiation
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    const long long p = 907; // Prime number
    const long long g = 6;   // Generator
    const long long a_Alice = 375; // Alice's private key
    const long long b_Bob = 294;   // Bob's private key

    // Calculate Alice's public key k(A)
    long long k_A = modPow(g, a_Alice, p);

    // Calculate Bob's public key k(B)
    long long k_B = modPow(g, b_Bob, p);

    // Calculate the common key K(AB) from Alice's perspective
    long long K_AB_Alice = modPow(k_B, a_Alice, p);

    // Calculate the common key K(AB) from Bob's perspective
    long long K_AB_Bob = modPow(k_A, b_Bob, p);

    // Output the results
    printf("Alice's public key k(A): %lld\n", k_A);
    printf("Bob's public key k(B): %lld\n", k_B);
    printf("Common key K(AB) computed by Alice: %lld\n", K_AB_Alice);
    printf("Common key K(AB) computed by Bob: %lld\n", K_AB_Bob);

    return 0;
}
