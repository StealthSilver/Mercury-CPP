# DSA with C++ — Module 5 Notes

LOOPS
they are used to run the logic again and agian. it is repeated block of code

1. for loops
2. while loops
3. do-while loops

FOR LOOPS -> a.cpp

for(initialisation; condition; updation){
// do some work
}
the loop runs while the condition is true

the variables defined inside the loop have the scope inside the scope only

INFINITE LOOP -> b.cpp

if the condition of the loop is always true then the loop keeps on running. this creates an infinite loop and it fills up the RAM of the system

c.cpp -> multiple times priniting
d.cpp -> print no 1 to n
e.cpp -> sum of n natural numbers , we can also use (n \* (n+1) )/ 2 -> faster

WHILE LOOP -> f.cpp

g.cpp -> pattern printing
h.cpp -> printing no n to 1
i.cpp -> sum of the digits of a number
j.cpp -> sum of the odd digits of a number

DO WHILE LOOP -> k.cpp

do {
do some work
}
while(consition)

do while loop runs atleast one time as the consition is checked later

BREAK STATEMENT -> l.cpp

used to break the loop in between when it is running if some condition matches. it exits the loop

m.cpp -> input until the condition matches

CONTINUE STATEMENT -> n.cpp

it is used to skip an iteration. if a given condition is true then the continue statement skips that iteration

o.cpp -> program where all the multiples entered by the user are visible except mult of 10

checking is a numebr is prime or not -> p.cpp
optimised way to check for primes -> is to check until sqrt(n), you need not check until n
