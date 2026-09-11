#include <bits/stdc++.h>
using namespace std;

void insertHeap(vector<int>& heap, int value) {

    // Step 1: Insert at the end
    heap.push_back(value);

    // Step 2: Heapify Up
    int i = heap.size() - 1;

    while (i > 0) {

        int parent = (i - 1) / 2;

        // Max Heap condition
        if (heap[parent] < heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
        }
        else {
            break;
        }
    }
}

int main() {

    vector<int> heap = {50, 30, 40, 10, 20};

    insertHeap(heap, 60);

    for (int x : heap) {
        cout << x << " ";
    }

    return 0;
}