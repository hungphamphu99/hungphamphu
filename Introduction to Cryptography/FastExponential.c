#include <stdio.h>

int dec_bin(int n, int binary[]) { //25 = 11001
    int i = 0;
    while (n > 0) {
        binary[i] = n % 2;
        n /= 2;
        i++;
    }
    return i;
}

long long mod(long long x, int h[], int t, long long n) {
    long long r = 1;
    for (int i = t - 1; i >= 0; i--) {
        r = (r * r) % n; //0
        if (h[i] == 1)
            r = (r * x) % n; //1
    }
    return r;
}

int main() {
    long long x, m;
    int h[32], t, e, i;

    printf("Enter base (x): ");
    scanf("%lld", &x);

    printf("Enter exponent (h) in decimal: ");
    scanf("%d", &e);

    t = dec_bin(e, h);

    printf("Enter modulus (m): ");
    scanf("%lld", &m);

    printf("Result: %lld^%d mod %lld = %lld\n", x, e, m, mod(x, h, t, m));
    
    return 0;
}
