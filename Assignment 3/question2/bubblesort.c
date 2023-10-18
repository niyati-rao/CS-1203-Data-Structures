/*==============================================================
            ALGORITHM FOR BUBBLE SORT IN AN ARRAY
================================================================*/
#include <stdio.h>

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {//we are solving from right to left i is just a counter
        for (int j = 0; j < n - i - 1; j++) {//going element by element until sorted part of array
            if (a[j] > a[j + 1]) {// if left is greater than right 
                // Swap a[j] and a[j+1]
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main() {
    int arr[] = {4, 1, 17, 21, 36, 45, 98, 69, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("BUBBLE SORT");
    printf("\nUnsorted array: ");// printing the unsorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, n);

    printf("\nSorted array: ");// printing the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}