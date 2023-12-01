#include <stdio.h>
#include <stdbool.h>

#define N 4

// Function to print the chessboard with 'Q' on queen positions
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check the left side of this row
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal on the left side
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j])
            return false;
    }

    return true;
}

// Recursive function to solve N-Queens problem and print all solutions
void solveNQueens(int board[N][N], int col) {
    if (col >= N) {
        printBoard(board);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            solveNQueens(board, col + 1);
            board[i][col] = 0; // Backtrack
        }
    }
}

int main() {
    int board[N][N] = {0};

    printf("All solutions for N-Queens problem:\n\n");
    solveNQueens(board, 0);

    return 0;
}
