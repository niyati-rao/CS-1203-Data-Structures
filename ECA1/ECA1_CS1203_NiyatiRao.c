//printing all possible permutations upto N iteratively
//where 1<=n<=8
//=====================================================

#include <stdio.h>

//swap funtion from prof's code
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to print the current permutation of the array.
void printArray(int arr[], int n) {
    for (int i = 0; i<n; i++) {
        if(i==0)//formating output
            printf("%d", arr[i]);
        else
            printf(", %d", arr[i]);
    }
    printf("\n");
}

//=========================MAIN LOGIC========================

int main() 
{
    //accepting a valid input
    int n;
    printf("Enter a value for n (between 1 and 8): ");
    scanf("%d", &n);
    if((n>8) ||(n<1))
    {
        printf("ERROR");
        return 0;
    }
    
    int arr[8];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    int count = 1; //keep track of number of permutations

    //first permutation is the array itself
    printf(" %d: ", count);
    printArray(arr, n);

    //=========================================================
    while (1) {
        int i,j;
        //finding largest index i such that a[i] < a[i + 1]
        for (i = n - 2; i>=0; i--) 
        {
            if (arr[i] < arr[i + 1])
                break;
        }

        if (i == -1)//stop condition
            break;
        //finding the largest index j>i such that a[j] > a[i]
        for (j = n - 1; j>i; j--) 
        {
            if (arr[j] > arr[i]) 
                break;
        }

        swap(&arr[i], &arr[j]);//swap to create new permutation
        //reverse from i+1 to the end
        int left = i + 1;
        int right = n - 1;
        while (left < right) 
        {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    //=========================================================
        //print permutation
        count++;
        printf(" %d: ", count);
        printArray(arr, n);
    }

    return 0;
}
