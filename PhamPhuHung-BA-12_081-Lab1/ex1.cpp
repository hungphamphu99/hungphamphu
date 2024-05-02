//pseudocode
//1. Start
//2. Input a positive integer num
//3. Check if num is less than 10
//  a. If true, output num
//   b. If false, proceed to the next step
//4. Initialize a variable firstDigit to the first digit of num
//5. Initialize a variable lastDigit to the last digit of num
//6. Calculate the number without the first and last digits by dividing num by 10, removing the last digit.
//7. Calculate the swapped number as (lastDigit * power(10, digits_in_newNum) + newnumber + firstDigit), where power(x, y) is a function that calculates x raised to the power of y.
//8. Output the swapped number as the result
//9. End

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cmath>
void swap(){
    int number, first, last  , digits ,newnumber;
    
    char input[100];
    int check = 0;
    //chỉ nhập số dương
    while (!check) {
        printf("Nhập một số nguyên dương: ");
        scanf("%s", input);

        check = 1;

        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
            check = 0;
            break;
        }
    }

    if (!check) {
        printf("Số không hợp lệ. Vui lòng nhập lại.\n");
    }
}
   // chuyển chuỗi thành số nguyên
    sscanf(input, "%d", &number);

       int n = number;
        last  = n % 10;
        digits   = (int)log10(n);

     
        first = (int)(n / pow(10, digits));

    newnumber  = last;
    newnumber *= (int) pow(10, digits);
    newnumber += n % ((int) pow(10, digits));
    newnumber -= last;
    newnumber += first;

        printf("Original number = %d \n", n);
        printf("Number after swapping first and last digit: %d \n", newnumber);
    
}
int main() {
    swap();
    return 0;
}

