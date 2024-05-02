#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMajority(int arr[], int size) {
    int count = 0, majority_index = 0;

    // Find a candidate for Majority
    for(int i = 0; i < size; i++) {
        if(count == 0)
            majority_index = i;

        if(arr[majority_index] == arr[i])
            count++;
        else
            count--;
    }

    // Verify the candidate
    count = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] == arr[majority_index])
            count++;
    }
    
    if(count > size/2)
        return arr[majority_index];
    else
        return -1; // No majority element
}

int* shift_array(int arr[], int length) {
    int* shifted_arr = (int*)malloc(length * sizeof(int));
    int temp = arr[length - 1];

    for (int i = length - 1; i > 0; i--) {
        shifted_arr[i] = arr[i - 1];
    }

    shifted_arr[0] = temp;
    return shifted_arr;
}

void find_keystream_bits(int arrx[], int arry[], int arrz[], int number_of_iterations) {
    for(int i = 0 ; i < number_of_iterations ; i++) {
        printf("Iteration: %d\n", i);

        int majority_val = findMajority((int[]){ arrx[8], arry[10], arrz[10] }, 3);
        printf("Keystream bits: %d ^ %d ^ %d = %d\n", arrx[18],arry[21],arrz[22],arrx[18]^arry[21]^arrz[22]);
        printf("\n");
        if(i == number_of_iterations - 1){
            break;
        };
        printf("Majority:(%d, %d, %d) = %d\n",arrx[8], arry[10], arrz[10], majority_val);

        if(arrx[8] == majority_val) {
            int* new_arrx = shift_array(arrx, 19);
            memcpy(arrx, new_arrx, 19 * sizeof(int));
            free(new_arrx);
        }
        if(arry[10] == majority_val) {
            int* new_arry = shift_array(arry, 22);
            memcpy(arry, new_arry, 22 * sizeof(int));
            free(new_arry);
        }
        if(arrz[10] == majority_val) {
            int* new_arrz = shift_array(arrz, 23);
            memcpy(arrz, new_arrz, 23 * sizeof(int));
            free(new_arrz);
        }
    }
}



int main() {
    int arrx[19] = {1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
    int arry[22] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1};
    int arrz[23] = {1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0};

    find_keystream_bits(arrx, arry, arrz, 10);
    return 0;
}
