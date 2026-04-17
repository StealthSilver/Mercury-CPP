#include <iostream>
#include <vector>
using namespace std;

// Function to convert 1D array into 2D array
vector<vector<int>> convertTo2D(vector<int> original, int m, int n)
{
    // Check if possible
    if (original.size() != m * n)
    {
        return {}; // empty 2D array
    }

    vector<vector<int>> mat(m, vector<int>(n));

    // Fill matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = original[i * n + j];
        }
    }

    return mat;
}

// Function to print matrix
void printMatrix(vector<vector<int>> mat)
{
    if (mat.empty())
    {
        cout << "Empty matrix\n";
        return;
    }

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> original = {1, 2, 3, 4};

    int m = 2, n = 2;

    vector<vector<int>> result = convertTo2D(original, m, n);

    printMatrix(result);

    return 0;
}