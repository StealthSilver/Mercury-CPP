// b.cpp
#include <iostream>
using namespace std;

// Function to create, use, and delete a 2D dynamic array
void create2DArray(int rows, int cols)
{
    // Step 1: Allocate memory for row pointers
    int **arr = new int *[rows];

    // Step 2: Allocate memory for each row
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    // Step 3: Assign values
    cout << "Filling array...\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = i + j;
        }
    }

    // Step 4: Display values
    cout << "2D Array:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Step 5: Deallocate memory (IMPORTANT)
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i]; // delete each row
    }
    delete[] arr; // delete array of pointers
}

int main()
{
    int rows = 3, cols = 4;

    create2DArray(rows, cols);

    return 0;
}