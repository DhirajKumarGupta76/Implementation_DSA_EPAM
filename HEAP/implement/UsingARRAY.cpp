#include <bits/stdc++.h>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        size = 0;
    }

    void insert(int val) {

        // Increase size
        size = size + 1;

        // Insert at last position
        int index = size - 1;
        arr[index] = val;

        // Heapify Up
        while (index > 0) {

            int parent = (index - 1) / 2;

            // Max Heap
            if (arr[parent] < arr[index]) {

                swap(arr[parent], arr[index]);

                // Move to parent
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void print() {

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    heap h;

    h.insert(23);
    h.insert(87);
    h.insert(90);
    h.insert(45);

    h.print();

    return 0;
}