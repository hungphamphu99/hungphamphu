#include <stdio.h>

int binarySearch(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == item) {
            return mid;
        } else if (arr[mid] < item) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

void insertionSortWithBinarySearch(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Find the position for the current element using binary search
        int pos = binarySearch(arr, key, 0, j);
        
        // Shift the elements to make space for the current element
        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Insert the current element in its correct position
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSortWithBinarySearch(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
