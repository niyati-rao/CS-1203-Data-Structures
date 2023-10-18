/*================================================================================
recursion is used so we assume that a smaller part of the problem is already solved
so  here we simplify the proble as a 2 disk problem
where
n-1 = top n-1 disks
largest = bottom disk

STEPS:
1. moving the top n-1 disks from S to T
2. moving the largest from S to D
3. Moving n-1 disk from T to D

these would be the steps for solving for 2 disks and we apply the same
recursively where n = n-1, the n=n-2 etc.

==================================================================================*/
#include <stdio.h>
int steps =0;//global variable to calculate the total number of steps required
void towerOfHanoi(int n, char source, char temp, char dest) {
    //when only disk 1 (smallest) needs to be moved to the destination from source
    if (n == 1) 
    {
        printf("Move disk 1 from %c to %c\n", source, dest);
        steps++; 
        return;// this is also the base case
    }
    //move n-1 disks from source to auxilary/ temp peg
    towerOfHanoi(n - 1, source, dest, temp);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    steps++;
    //move n-1 disks from auxilary/ temp peg to destination
    towerOfHanoi(n - 1, temp, source, dest);
}

int main() {
    int num;
    printf("Enter the number of disks: ");
    scanf("%d", &num);
    //function is called
    towerOfHanoi(num, 'S', 'T', 'D');
    printf("Total steps taken: %d\n",steps);
    return 0;
}
