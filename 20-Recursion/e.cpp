#include <iostream>
using namespace std;


int sumOfN(int n){

    // base case
    if(n==0){
        return 0;
    }

    // work + recursive call
    return n + sumOfN(n-1);
}

int main(){

int ans = sumOfN(10);
cout<<ans<<endl;
    return 0;
}