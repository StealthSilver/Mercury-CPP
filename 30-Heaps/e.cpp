// MODULE 30 — Heap sort (in-place, O(n log n))

#include <iostream>
#include <vector>
using namespace std;

void printVec(const vector<int>& a, int heapSize = -1) {
    int n = heapSize < 0 ? static_cast<int>(a.size()) : heapSize;
    cout << "[";
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        if (i) {
            cout << ", ";
        }
        if (i < n) {
            cout << a[i];
        } else {
            cout << "(" << a[i] << ")";  // already sorted tail
        }
    }
    cout << "]";
}

int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

void heapifyDown(vector<int>& a, int heapSize, int i) {
    while (true) {
        int largest = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        }
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest == i) {
            break;
        }
        swap(a[i], a[largest]);
        i = largest;
    }
}

void buildMaxHeap(vector<int>& a, bool trace = false) {
    int n = static_cast<int>(a.size());
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapifyDown(a, n, i);
        if (trace) {
            cout << "  heapifyDown index " << i << ": ";
            printVec(a, n);
            cout << "\n";
        }
    }
}

void heapSort(vector<int>& a, bool trace = false) {
    int n = static_cast<int>(a.size());
    if (n <= 1) {
        return;
    }

    cout << "Step 1 — build max-heap (O(n))\n";
    buildMaxHeap(a, trace);
    cout << "  max-heap: ";
    printVec(a, n);
    cout << "\n\n";

    cout << "Step 2 — extract max to end, n-1 times (O(n log n))\n";
    for (int heapSize = n; heapSize > 1; --heapSize) {
        swap(a[0], a[heapSize - 1]);
        if (trace) {
            cout << "  swap root with index " << heapSize - 1 << ": ";
            printVec(a, heapSize - 1);
            cout << "\n";
        }
        heapifyDown(a, heapSize - 1, 0);
        if (trace) {
            cout << "  heapifyDown(0): ";
            printVec(a, heapSize - 1);
            cout << "\n";
        }
    }
}

int main() {
    cout << "Module 30 — Heap sort (e.cpp)\n";
    cout << "=============================\n\n";

    vector<int> a = {4, 10, 3, 5, 1};
    cout << "Input:  ";
    printVec(a);
    cout << "\n\n";

    heapSort(a, true);

    cout << "\nSorted: ";
    printVec(a);
    cout << "\n\n";

    cout << "Time:  O(n log n)   Space: O(1) extra (in-place)\n";
    cout << "Note:  Same big-O as merge/quick sort; use std::sort in practice.\n";
    cout << "       Heap sort teaches heapify + guaranteed O(n log n) worst case.\n";

    return 0;
}
