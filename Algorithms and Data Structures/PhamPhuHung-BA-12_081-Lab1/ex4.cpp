//pseudocode
//1.  Define function to check if the number is prime or not
//2. Function isPrime(n)
//3.    if n is less than 2 then return False
//4.    for i from 2 to sqrt(n)
//5.        if n mod i equals 0 then return False
//6.    return True

//7.  Define function to check if the number is Sphenic or not
//8. Function isSphenic(n)
//9.     initialize countPrimes to 0 and prodPrimes to 1
//10.    for i from 2 to n
//11.        if i is prime and n mod i equals 0
//12.            increment countPrimes
//13.            update prodPrimes by multiplying it with i
//14.            divide n by i
//15.    if countPrimes equals 3 and prodPrimes equals the original number,
//        then return True
//16.   return False

#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


bool is_sphenic(int num) {
    if (num < 30) {
        return false;
    }
    for (int p = 2; p < num; p++) {
        if (is_prime(p)) {
            for (int q = p + 1; q < num; q++) {
                if (is_prime(q)) {
                    for (int r = q + 1; r < num; r++) {
                        if (is_prime(r) && p * q * r == num) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int n;
    printf("Enter  number: ");
    scanf("%d", &n);
    
    if (is_sphenic(n)) {
        printf("The number %d is a sphenic number.\n", n);
    } else {
        printf("The number %d is not a sphenic number.\n", n);
    }

    return 0;
}

//the overall complexity of this program is O(n^3 * sqrt(n)).

