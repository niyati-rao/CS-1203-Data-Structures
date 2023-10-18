/*==============================================================
            ALGORITHM FOR INSERTION SORT IN AN ARRAY
================================================================*/
#include <stdio.h>

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) //going through each element
    {
        int temp = a[i];//storing this value in a temp variable
        int j = i - 1;
        while (j >= 0 && a[j] > temp)//comparing the element with value of ith element
        {
            a[j + 1] = a[j];//if the value is greater then swap the elements
            j--;//move to previous index to compare towards left iteratively
        }
        a[j + 1] = temp;
    }
}

int main() {
    int arr[] = {4, 1, 17, 21, 36, 45, 98, 69, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("INSERTION SORT");
    printf("\nUnsorted array: ");// printing the unsorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    insertionSort(arr, n);

    printf("\nSorted array: ");// printing the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
