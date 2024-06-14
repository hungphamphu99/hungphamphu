
#include <stdio.h>
/*
  Pseudo-code for calculating the digit sum using Iteration:
 1. Set a variable's initial value to 0.

  2. Carry out the subsequent actions for every digit in the number:

  3. Take off the number's rightmost digit.

  4. Increase the total by the extracted digit.

  5. Subtract the number's rightmost digit.

 6. Return the sum as the result.
 */
int calculateDigitSum(int n) {

    int sum = 0;

    while (n > 0) {

        sum += n % 10;

        n /= 10;

    }

    return sum;

}

int calculateDigitSumRecursion(int n) {

    if (n == 0) {

        return 0;

    }

    return n % 10 + calculateDigitSumRecursion(n / 10);

}
int main() {

    int N1 = 103509;
    int N2 = 9512;
    int result = calculateDigitSum(N1);

    printf("Digit sum of %d is %d\n", N1, result);
    int result1 = calculateDigitSumRecursion(N2);

    printf("Digit sum of %d is %d\n", N2, result1);


    return 0;

}

//Time complexity is O(log10(N))
