//standard way ,accordint to copy notes;
#include<bits/stdc++.h>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    // INSERTION
    void insert(int val) {
        size = size + 1;

        int index = size;
        arr[index] = val;

        while(index > 1) {

            int parent = index / 2;

            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);

                // VERY IMPORTANT
                index = parent;
            }
            else {
                break;
            }
        }
    }

    // DELETE ROOT
    void deleteRoot() {

        // Heap is empty
        if(size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }

        // Put last element at root
        arr[1] = arr[size];

        // Reduce size
        size--;

        int index = 1;

        // Heapify Down
        while(index <= size) {

            int left = 2 * index;
            int right = 2 * index + 1;

            int largest = index;

            // Check left child
            if(left <= size && arr[left] > arr[largest]) {
                largest = left;
            }

            // Check right child
            if(right <= size && arr[right] > arr[largest]) {
                largest = right;
            }

            // If parent is already largest
            if(largest == index) {
                break;
            }

            swap(arr[index], arr[largest]);

            index = largest;
        }
    }

    // PRINT HEAP
    void print() {
        for(int i = 1; i <= size; i++) {
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

    cout << "Heap after insertion: ";
    h.print();

    h.deleteRoot();

    cout << "Heap after deletion: ";
    h.print();

    return 0;
}