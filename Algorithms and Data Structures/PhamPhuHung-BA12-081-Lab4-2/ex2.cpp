#include <stdio.h>

int Palindrome(int arr[], int start, int end) {

    if (start >= end) {
        return 1;
    }
    
    
    if (arr[start] == arr[end]) {
        return Palindrome(arr, start + 1, end - 1);
    }
    return 0;

}


int main() {

    int arr[] = {1, 2, 3, 2, 1}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    

    if (Palindrome(arr, 0, n - 1)) {
        printf("The array is a palindrome.\n");
    } else {
        printf("The array is not a palindrome.\n");
    }
    return 0;

}
//Time complexity is O(N)
