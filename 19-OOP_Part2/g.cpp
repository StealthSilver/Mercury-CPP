// Illustration: static variables.
//
// 1) Inside a function: `static` local is created and initialized *once* for the
//    whole program. Later calls reuse the same storage — it keeps its value.
//
// 2) Inside a class: `static` data members belong to the *class*, not each
//    object. There is exactly one shared variable for all instances. You must
//    define it exactly once in a .cpp file (unless `inline static` in C++17).

#include <iostream>

// --- 1) static in a function -------------------------------------------------

void visit() {
    static int times_called = 0;  // runs only the first time `visit` executes
    ++times_called;
    std::cout << "visit(): this is call #" << times_called << "\n";
}

// --- 2) static in a class --------------------------------------------------

class Widget {
   public:
    // One shared counter for every Widget — not stored inside each object.
    static int created_count;

    Widget() {
        ++created_count;
        my_id_ = created_count;
    }

    int id() const { return my_id_; }

   private:
    int my_id_{};  // per-object data
};

// Definition of the static member (single place in the program).
int Widget::created_count = 0;

int main() {
    std::cout << "--- function static ---\n";
    visit();
    visit();
    visit();

    std::cout << "\n--- class static ---\n";
    std::cout << "Widget::created_count before any object: " << Widget::created_count
              << "\n";

    Widget a;
    Widget b;
    Widget c;

    std::cout << "a.id()=" << a.id() << " b.id()=" << b.id() << " c.id()=" << c.id()
              << "\n";
    std::cout << "Widget::created_count (shared): " << Widget::created_count << "\n";

    return 0;
}
