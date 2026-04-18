#include <iostream>
#include <vector>
using namespace std;

int main()
{

    // 1. Empty 2D vector
    vector<vector<int>> matrix1;

    // Adding rows manually
    matrix1.push_back({1, 2});
    matrix1.push_back({3, 4});

    cout << "Matrix 1 (Empty -> Filled):" << endl;
    for (auto row : matrix1)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;

    //  2. Fixed size initialization (n x m with default value 0)
    int n = 2, m = 3;
    vector<vector<int>> matrix2(n, vector<int>(m, 0));

    cout << "Matrix 2 (Fixed size initialized with 0):" << endl;
    for (auto row : matrix2)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;

    //  3. Initialization with values
    vector<vector<int>> matrix3 = {
        {1, 2, 3},
        {4, 5, 6}};

    cout << "Matrix 3 (Initialized with values):" << endl;
    for (auto row : matrix3)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}