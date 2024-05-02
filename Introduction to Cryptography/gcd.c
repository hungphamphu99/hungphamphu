#include <stdio.h>

// Function to calculate GCD
int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int main() {
    int num1 = 215;
    int num2 = 592;
    int result = gcd(num1, num2);
    
    printf("The GCD of %d and %d is %d.\n", num1, num2, result);
    
    return 0;
}
