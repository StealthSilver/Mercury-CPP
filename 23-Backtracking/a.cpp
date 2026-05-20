#include <iostream>
using namespace std;


void printArray(int *arr, int n, int i){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void changeArray(int *arr, int n, int i){

    if(i == n){
        printArray(arr, n, i);
        return;
    }
    arr[i] = i+1;
    changeArray(arr, n, i+1);
    arr[i] -=2;
}


int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    changeArray(arr, n,0);
    printArray(arr, n, 0);
    return 0;
}