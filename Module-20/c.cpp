#include <iostream>
using namespace std;

void print(int n){{

    // base case
    if(n==0){
        return;
    }

    // logic for the function call
    cout<<n<<" ";

    // recursive call
    print(n-1);
    }
}

int main(){

   print(20);

    return 0;
}