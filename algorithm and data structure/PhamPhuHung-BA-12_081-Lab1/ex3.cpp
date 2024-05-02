#include <stdio.h>

struct Complex {
    double real;
    double imag;
};

struct Complex addComplex(struct Complex a, struct Complex b) {
    struct Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

struct Complex multiplyComplex(struct Complex a, struct Complex b) {
    struct Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

int main() {
    struct Complex num1, num2, sum, product;
    
    printf("Enter the real and imaginary parts of the first complex number:\n");
    scanf("%lf %lf", &num1.real, &num1.imag);

    printf("Enter the real and imaginary parts of the second complex number:\n");
    scanf("%lf %lf", &num2.real, &num2.imag);

   
    sum = addComplex(num1, num2);
    printf("Sum: %.2lf + %.2lfi\n", sum.real, sum.imag);
    
    
    product = multiplyComplex(num1, num2);
    printf("Product: %.2lf + %.2lfi\n", product.real, product.imag);

    return 0;
}

