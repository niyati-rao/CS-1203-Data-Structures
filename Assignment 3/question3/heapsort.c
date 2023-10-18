//==============================================================
//slightly modified code give by Professor with delte function 
//and minor changes
//==============================================================
#include <stdio.h>  
#define ARRSIZE 12

int swpcnt, cmpcnt;

// Function to swap two elements  
void swap(int* a, int* b) {  
    int t = *a;  
    *a = *b;  
    *b = t;  
    swpcnt++;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    cmpcnt++;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    cmpcnt++;

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to print the array  
void printArray(int arr[], int size) {  
    int i;  
    for (i = 0; i < size; i++)  
        printf("%d ", arr[i]);  
    printf("\n");  
}

int main() {
    int arr[] = {8, 19, 9, 11, 12, 11, 13, 5, 6, 7, 3, 17};
    int n = ARRSIZE;

    swpcnt = 0; cmpcnt = 0;

    printf("Unsorted array: \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    printf("Swap %d Comparison %d\n", swpcnt, cmpcnt);
    return 0;
}