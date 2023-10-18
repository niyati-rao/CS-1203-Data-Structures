/*==========================================================
the eight queen problem can be recursively solved by finding
the first safe spot recurssively, the 8 queen problem has 92
possible solutions.

============================================================*/
#include <stdio.h>
#define N 8

//=======FUNCTION TO PRINT THE BOARD FOR EACH SOLUTION=======
int no_sol=0;//keeping track of all the possible solutions 
void print_board(int board[N][N]) {
    no_sol++;
    printf("SOLUTION: %d\n", no_sol);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])//if the spot is set to 1
                printf(" Q ");
            else
                printf(((i + j) % 2 )== 0? ":: " : "   ");// where :: represents a black box and empty is white
        }
        printf("\n");
    }
    printf("\n");
}
//===========================================================
//this function checks for the different ways queen can move
int isSafe(int board[N][N], int r, int c) {
    //row is handled already because we move to next row
    //checking along the column
    for (int i = 0; i < c; i++) 
    {
        if (board[r][i])
            return 0; //unsafe
    }
    //checking along the diagonal upper part that goes in \ direction
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) 
    {
        if (board[i][j])
            return 0; // False
    }
    // checking along the diagonal lower part that goes in / direction
    for (int i = r, j = c; i < N && j >= 0; i++, j--) 
    {
        if (board[i][j])
            return 0; // False
    }
    return 1; // True
}

//=======RECURSSIVE FUNCTION TO SOLVE FOR 8 QUEENS===============
int solveNQueens(int board[N][N], int col) {
    if (col >= N) {//when all the queens have been placed
        print_board(board);
        return 1; //true
    }
    int res = 0; //false
    for (int i = 0; i < N; i++) {//finding first safe spot
        if (isSafe(board, i, col)) {
            board[i][col] = 1; //when spot is safe place queen
            res = solveNQueens(board, col + 1) || res;
            board[i][col] = 0; //backtrack
        }
    }

    return res;
}
//======MAIN FUCTION FOR DRIVER ====================================
int main() {
    int board[N][N] = {0};//setting all spaces as 0
    if (solveNQueens(board, 0) == 0) {
        printf("No solution exists");
    }
    return 0;
}
//====== END OF PROGRAM =============================================
