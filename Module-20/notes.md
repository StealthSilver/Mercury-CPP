# DSA with C++ — Module 19 Notes

RECURSION -> a.cpp

When a function repeatedly calls itself then its recursion

all the recursion questions can be done by iterations (loops) but they are generally easier with recursion

It is a method of solving computational problems where the solution depends on solutions to smaller instances of the same problem

1. base case is required
2. logic of the function call
3. inner function must be known

main -> func -> func -> func -> base case 
then it returns

the base case is really imprortant

recursion - mathematical understanding -> b.cpp

f(x) = x^2
f(f(x)) = (x^2)^2

the composite funcitoans are way of recursion 

for factorial - f(n) = n!
f(n) = n * f(n-1) -> this is a reccurence relation

f(5) = 5*f(4)
         f(4) = 4*f(3)
                  f(3) = 3*f(2)
                           f(2) = 2*f(1)
                                    f(1) = 1*f(0) and f(0) is the base case so it returns 1


recursion in memory

factorial(5)

new stack frame creates for n=5 -> calls factorial 4 
new stack frame creates for n=4-> calls factorial 3
new stack frame creates for n=3-> calls factorial 2
new stack frame creates for n=2-> calls factorial 1 
new stack frame creates for n=1-> calls factorial 0 -> factorial(0) , returns 1 , removes from the stack frame 
factorial(1) , returns 1 * 1 , removes from the stack frame 
factorial(2) , returns 2 * 1 , removes from the stack frame 
factorial(3) , returns 3 * 2 , removes from the stack frame 
factorial(4) , returns 4 * 6 , removes from the stack frame 
factorial(5) , returns 5 * 24 , removes from the stack frame 

Print numbers is decreasing order -> c.cpp

print (n) -> prints dec order for n
assume print(n-1) works

print numbers in ascending order -> d.cpp

STACK OVERFLOW

this happens when there is infinite recursion

1. local variable : if a lot of local variables are created then all of the stack memory is filled so stack overflows
2. if the base case is missing -> recursion will not stop and the function calls will exceed the memory

stack oevrflow gives segmentation fault

sum of n natural numbers using recursion -> e.cpp

print the Nth Fibonacci Number -> f.cpp

0, 1, 1, 2, 3, 5, 8, 13, 21 ...

recurrance relation = fib(n) = fib(n-1) + fib(n-2)
base case -> fib(0) = 0, fib(1) = 1

### Recursion tree for fib(5)

Each node splits into `fib(n-1)` (left) and `fib(n-2)` (right). Leaves are base cases `fib(0)=0` and `fib(1)=1`.

```
                              fib(5)
                             /      \
                        fib(4)      fib(3)
                       /    \       /    \
                  fib(3)  fib(2) fib(2) fib(1)→1
                 /   \   /   \   /   \
            fib(2) fib(1) fib(1) fib(0) fib(1) fib(0)
           /   \    →1     →1     →0     →1     →0
      fib(1) fib(0)
        →1     →0
```

**Bubble values up (each node = left + right):**

- `fib(2)` appears many times: each time `1 + 0 = 1`.
- `fib(3)` = `fib(2)+fib(1)` = `1+1 = 2` (twice in the tree for the two `fib(3)` nodes under `fib(5)` and `fib(4)`).
- `fib(4)` = `2 + 1 = 3`.
- `fib(5)` = `3 + 2 = 5`.

So **fib(5) = 5**. The wide tree and repeated `fib(2)`, `fib(3)`, … nodes show why naive recursion is slow (exponential work); memoization or iteration fixes that.