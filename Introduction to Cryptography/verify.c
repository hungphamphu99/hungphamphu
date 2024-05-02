#include <stdio.h>

// Function to perform modular exponentiation.
// It returns (base^exponent) % modulus.
long long modular_pow(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
    
}

// Function to verify an ElGamal signature
int verify_elgamal_signature(long long p, long long alpha, long long beta, long long x, long long r, long long s) {
    // Check for invalid r and s values
    if (r <= 0 || r >= p || s <= 0 || s >= p - 1) {
        return 0;
    }

    // Calculate v1 and v2 for the verification
    long long v1 = modular_pow(alpha, x, p);
    long long v2 = (modular_pow(beta, r, p) * modular_pow(r, s, p)) % p;
    
    // Verify the signature
    return v1 == v2;
   print("%lld",v1);
}

int main() {
    long long p = 877; // The prime number
    long long alpha = 6; // The primitive root
    long long beta = 349; // The public key part β

    // Messages and signatures
    long long x1 = 696, r1 = 760, s1 = 632;
    long long x2 = 696, r2 = 771, s2 = 819;

    // Verify the signatures for both messages
    int verification_result_1 = verify_elgamal_signature(p, alpha, beta, x1, r1, s1);
    int verification_result_2 = verify_elgamal_signature(p, alpha, beta, x2, r2, s2);

    printf("Verification result for message 1: %s\n", verification_result_1 ? "True" : "False");
    printf("Verification result for message 2: %s\n", verification_result_2 ? "True" : "False");

    return 0;
}
