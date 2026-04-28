#include <iostream>
#include <string>
using namespace std;

// Destructor ~Name() runs when the object is destroyed: end of scope, delete, container
// erase, etc. Use it to release resources that won’t clean themselves (e.g. `new`).

class Resource {
    int* data;        // heap — not freed automatically when the object “goes away” without ~Resource
    string label;

public:
    Resource(const string& name, int value) : label(name) {
        data = new int(value);
        cout << "  [ctor]  " << label << "  new int @ " << data << " = " << *data << "\n";
    }

    ~Resource() {
        cout << "  [dtor]  " << label << "  delete heap @ " << data << "\n";
        delete data;
    }

    void show() const { cout << "    " << label << " *data = " << *data << "\n"; }
};

class IntBuffer {
    int* arr;
    size_t n;

public:
    IntBuffer(size_t len) : n(len) {
        arr = new int[n];
        for (size_t i = 0; i < n; ++i) { arr[i] = static_cast<int>(i); }
        cout << "  [ctor]  IntBuffer: new int[" << n << "] @ " << arr << "\n";
    }
    ~IntBuffer() {
        cout << "  [dtor]  IntBuffer: delete[] @ " << arr << "\n";
        delete[] arr;
    }
};

int main() {
    cout << "1) Enter block { } — one Resource; leaving the block runs the destructor.\n\n";
    {
        Resource r("block-local", 42);
        r.show();
        cout << "\n  (end of block — r’s destructor runs here, before the next line)\n\n";
    }

    cout << "2) After the block, r is gone; heap was released in ~Resource().\n\n";

    cout << "3) Dynamic array: IntBuffer uses delete[] in the destructor\n\n";
    { IntBuffer buf(4); }

    cout << "\n4) end of main — global/static objects would destroy after this return.\n";
    return 0;
}
