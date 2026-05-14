// ---------------------------------------------------------------------------
// Question (concept — original snippet had syntax typos: `std::cout`, `<<`,
// `std::endl`, braces, and `main` must be outside the class)
//
// Given:
//   class A { ... constructor prints "Constructor A", destructor "Destructor A" };
//   class B : public A { ... same for B };
//   int main() { B obj; return 0; }
//
// Predict the exact order of lines printed when this program runs.
// Hint: base subobject is built before the derived part; destruction is the
// reverse of construction (LIFO for the object as a whole).
// ---------------------------------------------------------------------------

#include <iostream>

class A {
   public:
    A() { std::cout << "Constructor A" << std::endl; }
    ~A() { std::cout << "Destructor A" << std::endl; }
};

class B : public A {
   public:
    B() { std::cout << "Constructor B" << std::endl; }
    ~B() { std::cout << "Destructor B" << std::endl; }
};

int main() {
    B obj;
    return 0;
}

// --- Answer (predict first, then compile: c++ -std=c++17 -o j j.cpp && ./j) ---
// Constructor A
// Constructor B
// Destructor B
// Destructor A
