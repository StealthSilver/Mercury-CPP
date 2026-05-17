#include <iostream>
using namespace std;

const int N = 3; // rows
const int M = 3; // columns

// Count paths from (row, col) to (N-1, M-1) using only right / down moves
int countWays(int row, int col) {
    if (row >= N || col >= M)
        return 0;

    if (row == N - 1 && col == M - 1)
        return 1;

    int rightWays = countWays(row, col + 1);
    int downWays = countWays(row + 1, col);

    return rightWays + downWays;
}

int main() {
    cout << "Grid size: " << N << " x " << M << endl;
    cout << "From (0,0) to (" << N - 1 << "," << M - 1 << ")" << endl;
    cout << "Total ways: " << countWays(0, 0) << endl;

    return 0;
}
