#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to compute (base^exponent) % modulus
long long mod_pow(long long base, long long exponent, long long modulus) {
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


// Function to compute modular multiplicative inverse of a under modulus m
long long mod_inverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1) return 0;

    // Apply extended Euclid Algorithm
    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;

        // m is remainder now, process same as Euclid's algo
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0) x1 += m0;

    return x1;
}

// Function to generate Elgamal signature
void elgamal_signature(long long x, long long kE, long long p, long long alpha, long long d, long long* r, long long* s) {
    *r = mod_pow(alpha, kE, p);
    *s = ((x - d * (*r)) * mod_inverse(kE, p-1)) % (p-1);
    if (*s < 0) *s += (p-1); // Ensure s is positive
}

bool verify_elgamal_signature(long long x, long long r, long long s, long long p, long long alpha, long long beta) {
    long long left_side = mod_pow(alpha, x, p);
    long long right_side = (mod_pow(beta, r, p) * mod_pow(r, s, p)) % p;
    printf("t = %lld, alpha^x = %lld\n", left_side, right_side);
    return left_side == right_side;
}

int main() {
    long long p = 877, alpha = 6, beta = 349, d = 59;
    long long kE_A = 113, kE_B = 119;
    long long k_A = 791, ID_A = 1;
    long long k_B = 499, ID_B = 2;
    long long x_A, x_B;
    long long r_A, s_A, r_B, s_B;

    // Compute x(A) and x(B)
    x_A = 294 * k_A + ID_A;
    x_B = 294 * k_B + ID_B;

    // Compute signatures for Cert_A and Cert_B
    elgamal_signature(x_A, kE_A, p, alpha, d, &r_A, &s_A);
    elgamal_signature(x_B, kE_B, p, alpha, d, &r_B, &s_B);

    printf("Cert_A Signature: (r_A, s_A) = (%lld, %lld)\n", r_A, s_A);
    printf("Cert_B Signature: (r_B, s_B) = (%lld, %lld)\n", r_B, s_B);

    bool verify_A = verify_elgamal_signature(x_A, r_A, s_A, p, alpha, beta);
    bool verify_B = verify_elgamal_signature(x_B, r_B, s_B, p, alpha, beta);

    printf("Verification of Cert_A: %s\n", verify_A ? "True" : "False");
    printf("Verification of Cert_B: %s\n", verify_B ? "True" : "False");

    return 0;
}
