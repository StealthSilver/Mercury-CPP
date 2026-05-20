#include <iostream>
using namespace std;

/*
 * Recursion tree for fib(5) — fib(n) = fib(n-1) + fib(n-2); fib(0)=0, fib(1)=1
 *
 *                         fib(5)
 *                        /      \
 *                   fib(4)      fib(3)
 *                  /    \       /    \
 *             fib(3)  fib(2) fib(2) fib(1)→1
 *            /   \   /   \   /   \
 *       fib(2) fib(1) ... (leaves fib(0)→0, fib(1)→1)
 *
 * Result: fib(5) = 5. Same subproblems repeat → O(2^n) naive; memo/loop is O(n).
 */

int fib(int n ){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    return fib(n-1) + fib(n-2);
}

int main(){

    int ans = fib(6);
    cout<<ans<<endl;

    return 0;
}