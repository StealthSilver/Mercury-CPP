# DSA with C++ — Module 19 Notes

RECURSION -> a.cpp

When a function repeatedly calls itself then its recursion

all the recursion questions can be done by iterations (loops) but they are generally easier with recursion

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

