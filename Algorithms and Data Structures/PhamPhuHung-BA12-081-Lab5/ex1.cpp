#include <stdio.h>

int binarySearch(int arr[], int n, int v) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < v) {
            low = mid + 1;
        } else if (arr[mid] > v) {
            high = mid - 1;
        } else {
           
            high = mid - 1;
        }
    }

   
    return low;
}

void insertValue(int arr[], int *n, int v, int position) {
   
    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = v;


    (*n)++;
}

int main() {
    int arr[6] = {1, 3, 5, 7, 9, 11 };
    int n = 6;
    int v = 4;

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int position = binarySearch(arr, n, v);
    insertValue(arr, &n, v, position);

    printf("\nArray after inserting %d at position %d: ", v, position);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

