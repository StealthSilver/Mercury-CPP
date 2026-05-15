#include <iostream>
using namespace std;

int firstOccurance(int *arr, int n, int i, int target){
    if(i==n){
        return -1;
    }

    if(arr[i] == target){
        return i;
    }

    return firstOccurance(arr, n, i+1, target);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    int target = 3;
    int i = 0;
    int ans = firstOccurance(arr, n, i, target);
    cout<<ans<<endl;
    return 0;
}