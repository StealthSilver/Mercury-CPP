#include <iostream>
using namespace std;

void print(int n){{

    // base case
    if(n==0){
        return;
    }

    // recursive call
    print(n-1);

    // logic for the function call
    cout<<n<<" "; 
    }
}

int main(){

   print(20);

    return 0;
}