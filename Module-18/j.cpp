#include <iostream>
#include <cstddef>
using namespace std;

class ShallowArray {
    int* arr;
    size_t n;

public:
    ShallowArray(size_t len, int fill) : n(len) {
        arr = new int[n];
        for (size_t i = 0; i < n; ++i) { arr[i] = static_cast<int>(fill); }
    }

    // Shallow: copy the pointer, not a new array — both now alias the same memory.
    ShallowArray(const ShallowArray& o) : arr(o.arr), n(o.n) {}

    void set(size_t i, int v) {
        if (i < n) { arr[i] = v; }
    }
    int get(size_t i) const { return (i < n) ? arr[i] : -1; }
    const int* heapAddress() const { return arr; }
    size_t length() const { return n; }
};

// --- Deep copy: allocate a new array and copy each element — independent data. ---
class DeepArray {
    int* arr;
    size_t n;

public:
    DeepArray(size_t len, int fill) : n(len) {
        arr = new int[n];
        for (size_t i = 0; i < n; ++i) { arr[i] = static_cast<int>(fill); }
    }

    // Deep: new buffer, then copy values — the two objects do not share memory.
    DeepArray(const DeepArray& o) : n(o.n) {
        arr = new int[n];
        for (size_t i = 0; i < n; ++i) { arr[i] = o.arr[i]; }
    }

    ~DeepArray() { delete[] arr; }

    void set(size_t i, int v) {
        if (i < n) { arr[i] = v; }
    }
    int get(size_t i) const { return (i < n) ? arr[i] : -1; }
    const int* heapAddress() const { return arr; }
    size_t length() const { return n; }
};

static void print3(const char* label, int a, int b, int c) {
    cout << "  " << label << ": [" << a << ", " << b << ", " << c << "]\n";
}

int main() {
    cout << "---- Shallow copy: same buffer address, shared data ----\n";
    {
        ShallowArray s(3, 1);
        ShallowArray t = s; // copy ctor — copies `arr` pointer

        cout << "  s and t's heap array address (same?): "
             << s.heapAddress() << " vs " << t.heapAddress() << " -> "
             << (s.heapAddress() == t.heapAddress() ? "same (shallow)\n" : "diff\n");

        t.set(0, 9);
        cout << "  After t.set(0, 9), s also sees 9 in index 0:\n";
        print3("s via s", s.get(0), s.get(1), s.get(2));
    }
    cout << "(end of block: ShallowArray has no delete[] in this demo; see comment above.)\n\n";

    cout << "---- Deep copy: different buffer address, independent data ----\n";
    {
        DeepArray a(3, 1);
        DeepArray b = a; // copy ctor — new array, copied elements

        cout << "  a and b's heap array address: "
             << a.heapAddress() << " vs " << b.heapAddress() << " -> different (deep)\n";

        b.set(0, 9);
        cout << "  After b.set(0, 9), a is unchanged:\n";
        print3("a", a.get(0), a.get(1), a.get(2));
        print3("b", b.get(0), b.get(1), b.get(2));
    }
    cout << "(end of block: each ~DeepArray deletes its own buffer — safe.)\n";

    return 0;
}
