#include <iostream>
using namespace std;

const int N = 4;

// U(x,y-1)  D(x,y+1)  L(x-1,y)  R(x+1,y)  — x = row, y = col
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
char moveChar[] = {'U', 'D', 'L', 'R'};

bool isSafe(int maze[N][N], bool visited[N][N], int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < N && maze[row][col] == 1 &&
           !visited[row][col];
}

void findPaths(int maze[N][N], bool visited[N][N], int row, int col, string &path) {
    if (row == N - 1 && col == N - 1) {
        cout << path << endl;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nextRow = row + dr[i];
        int nextCol = col + dc[i];

        if (!isSafe(maze, visited, nextRow, nextCol))
            continue;

        visited[nextRow][nextCol] = true;
        path.push_back(moveChar[i]);
        findPaths(maze, visited, nextRow, nextCol, path);
        path.pop_back();
        visited[nextRow][nextCol] = false;
    }
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1},
    };

    bool visited[N][N] = {};
    string path;

    if (maze[0][0] == 0 || maze[N - 1][N - 1] == 0) {
        cout << "No path possible.\n";
        return 0;
    }

    visited[0][0] = true;
    cout << "All paths from (0,0) to (" << N - 1 << "," << N - 1 << "):\n";
    findPaths(maze, visited, 0, 0, path);

    return 0;
}
