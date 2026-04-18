#include <iostream>
#include <vector>
using namespace std;

int main()
{

    // Initialize a 2D vector
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // 1. Traversal using index-based loops
    cout << "Traversal using index-based loops:" << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // 2. Traversal using range-based loops
    cout << "Traversal using range-based loops:" << endl;
    for (auto row : matrix)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}