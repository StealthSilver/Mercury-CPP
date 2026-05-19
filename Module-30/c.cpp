// MODULE 30 — Build max-heap from scratch using vector (no Node class)

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> arr;

    int parent(int i) const { return (i - 1) / 2; }
    int leftChild(int i) const { return 2 * i + 1; }
    int rightChild(int i) const { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && arr[i] > arr[parent(i)]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int n = static_cast<int>(arr.size());
        while (true) {
            int largest = i;
            int l = leftChild(i);
            int r = rightChild(i);

            if (l < n && arr[l] > arr[largest]) {
                largest = l;
            }
            if (r < n && arr[r] > arr[largest]) {
                largest = r;
            }
            if (largest == i) {
                break;
            }
            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

public:
    bool empty() const { return arr.empty(); }
    int size() const { return static_cast<int>(arr.size()); }

    int top() const {
        if (arr.empty()) {
            throw runtime_error("top() on empty heap");
        }
        return arr[0];
    }

    void push(int x) {
        arr.push_back(x);
        heapifyUp(static_cast<int>(arr.size()) - 1);
    }

    void pop() {
        if (arr.empty()) {
            throw runtime_error("pop() on empty heap");
        }
        arr[0] = arr.back();
        arr.pop_back();
        if (!arr.empty()) {
            heapifyDown(0);
        }
    }

    void print() const {
        cout << "[";
        for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
            if (i) {
                cout << ", ";
            }
            cout << arr[i];
        }
        cout << "]";
    }
};

int main() {
    cout << "Module 30 — Max-heap from scratch (vector, no Node)\n";
    cout << "=================================================\n\n";

    MaxHeap heap;

    cout << "push(5) push(1) push(9) push(3) push(7)\n";
    for (int x : {5, 1, 9, 3, 7}) {
        heap.push(x);
        cout << "  after push(" << x << "): ";
        heap.print();
        cout << "  top() = " << heap.top() << "\n";
    }

    cout << "\ntop() = " << heap.top() << "  [O(1)]\n";
    cout << "size() = " << heap.size() << "\n\n";

    cout << "pop order (top + pop, each pop O(log n)):\n";
    while (!heap.empty()) {
        cout << "  top=" << heap.top() << "  array=";
        heap.print();
        cout << "\n";
        heap.pop();
    }

    cout << "\nempty() = " << (heap.empty() ? "true" : "false") << "\n";
    cout << "\nWhy vector, not Node*?\n";
    cout << "  - Index math: parent/child in O(1)\n";
    cout << "  - Contiguous memory, no pointer chasing\n";
    cout << "  - push/pop stay O(log n) with swaps only\n";

    return 0;
}
