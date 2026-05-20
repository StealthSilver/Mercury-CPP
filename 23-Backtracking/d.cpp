#include <iostream>
using namespace std;

const int N = 7;

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Place queens row by row; when row == N, one full solution is found
void solveNQueens(int board[N][N], int row, int &solutionCount) {
    if (row == N) {
        printBoard(board);
        solutionCount++;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (!isSafe(board, row, col))
            continue;

        board[row][col] = 1;
        solveNQueens(board, row + 1, solutionCount);
        board[row][col] = 0; // backtrack
    }
}

int main() {
    int board[N][N] = {};
    int solutionCount = 0;

    cout << "All solutions for " << N << "-Queens:\n\n";
    solveNQueens(board, 0, solutionCount);
    cout << "Total solutions: " << solutionCount << endl;

    return 0;
}
