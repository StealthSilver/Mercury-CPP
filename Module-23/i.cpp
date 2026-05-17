#include <iostream>
using namespace std;

const int N = 8;

// Knight move offsets (8 L-shaped jumps)
int rowMove[] = {2, 1, -1, -2, -2, -1, 1, 2};
int colMove[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isSafe(int board[N][N], int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < N && board[row][col] == -1;
}

bool solveKnight(int board[N][N], int row, int col, int moveCount) {
    if (moveCount == N * N)
        return true;

    for (int i = 0; i < 8; i++) {
        int nextRow = row + rowMove[i];
        int nextCol = col + colMove[i];

        if (!isSafe(board, nextRow, nextCol))
            continue;

        board[nextRow][nextCol] = moveCount;
        if (solveKnight(board, nextRow, nextCol, moveCount + 1))
            return true;
        board[nextRow][nextCol] = -1;
    }
    return false;
}

int main() {
    int board[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            board[i][j] = -1;
    }

    board[0][0] = 0;

    if (!solveKnight(board, 0, 0, 1)) {
        cout << "No knight's tour exists for N = " << N << endl;
        return 0;
    }

    cout << "Knight's tour (visit order) for N = " << N << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
