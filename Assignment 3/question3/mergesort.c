//==============================================================
//CODE AS GIVEN BY PROFESSOR
//==============================================================
// C program for Merge Sort 
#include <stdio.h> 
#include <stdlib.h> 

#define ARRSIZE 12;
int cp1, cmp1;
  
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    // Create temp arrays 
    int L[n1], R[n2]; 
  
    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i]; 
	cp1++;
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
	cp1++;
    } 
  
    // Merge the temp arrays back 
    // into arr[l..r] 
    // Initial index of first subarray 
    i = 0; 
  
    // Initial index of second subarray 
    j = 0; 
  
    // Initial index of merged subarray 
    k = l; 
    while (i < n1 && j < n2) { 
	cmp1++;
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements 
    // of L[], if there are any 
    while (i < n1){ 
        arr[k] = L[i]; 
        i++; 
        k++; 
        cp1++;
    } 
  
    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
        cp1++;
    } 
} 
  
// l is for left index and r is 
// right index of the sub-array 
// of arr to be sorted 
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids 
        // overflow for large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
// UTILITY FUNCTIONS 
// Function to print an array 
void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = {8, 19, 9, 11, 12, 11, 13, 5, 6, 7, 3, 17}; 
    int arr_size = ARRSIZE; 

    cp1 = 0; cmp1 = 0;
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 

    printf("Copy count %d, Comparison Count %d\n", cp1, cmp1);
    return 0; 
}