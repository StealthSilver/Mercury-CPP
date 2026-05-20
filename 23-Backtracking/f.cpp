#include <iostream>
using namespace std;

const int N = 9;

bool isValid(int board[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }

    int boxRow = (row / 3) * 3;
    int boxCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[boxRow + i][boxCol + j] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] != 0)
                continue;

            for (int num = 1; num <= 9; num++) {
                if (!isValid(board, row, col, num))
                    continue;

                board[row][col] = num;
                if (solveSudoku(board))
                    return true;
                board[row][col] = 0; // backtrack
            }
            return false;
        }
    }
    return true;
}

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0)
                cout << " ";
        }
        cout << endl;
        if ((i + 1) % 3 == 0)
            cout << endl;
    }
}

int main() {
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
    };

    cout << "Puzzle:\n";
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "Solution exists: Yes\n\n";
        cout << "Solved board:\n";
        printBoard(board);
    } else {
        cout << "Solution exists: No\n";
    }

    return 0;
}
