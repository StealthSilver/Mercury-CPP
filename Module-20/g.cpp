#include <iostream>
using namespace std;

bool isSorted(int *arr, int n, int i){
    if(i == n-1){
        return true;
    }

    if(arr[i] > arr[i+1]){
        return false;
    }

    return isSorted(arr, n, i+1);
    }   


int main(){
int arr[] = {1, 2, 3, 4, 5};
int n = sizeof(arr) / sizeof(int);

bool ans = isSorted(arr, n,0);

cout<<ans<<endl;

    return 0;
}