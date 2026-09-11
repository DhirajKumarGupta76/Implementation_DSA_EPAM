#include <bits/stdc++.h>
using namespace std;


// Node of Doubly Linked List
class Node {
public:
    int key;
    int val;

    Node* prev;
    Node* next;

    Node(int n, int k) {
        key = n;
        val = k;
        prev = NULL;
        next = NULL;
    }
};


class LRUCache {

private:

    int capacity;

    // key -> address of Node
    unordered_map<int, Node*> mpp;

    Node* head;
    Node* tail;


public:

    // Constructor
    LRUCache(int n) {

        capacity = n;

        // Dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }


    // Remove node from linked list
    void deleteNode(Node* node) {

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }


    // Insert node just after head
    // This makes it MOST RECENTLY USED
    void insert(Node* node) {

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }


    // FETCH operation
    void fetch(int chunk_id) {

        // Chunk already exists
        if (mpp.find(chunk_id) != mpp.end()) {

            Node* store = mpp[chunk_id];

            // Remove from current position
            deleteNode(store);

            // Move to front
            insert(store);

            return;
        }


        // Chunk does not exist
        // Check if memory is full
        if (mpp.size() == capacity) {

            // Least recently accessed chunk
            Node* lru = tail->prev;

            // Remove from map
            mpp.erase(lru->key);

            // Remove from linked list
            deleteNode(lru);

            // Free memory
            delete lru;
        }


        // Create new node
        Node* newnode = new Node(chunk_id, chunk_id);

        // Store in map
        mpp[chunk_id] = newnode;

        // Insert at front
        insert(newnode);
    }


    // STATUS operation
    void status() {

        Node* curr = head->next;

        // If memory is empty
        if (curr == tail) {
            cout << "EMPTY" << endl;
            return;
        }

        // Print MRU -> LRU
        while (curr != tail) {

            cout << curr->key;

            if (curr->next != tail) {
                cout << " ";
            }

            curr = curr->next;
        }

        cout << endl;
    }
};


int main() {

    int C, N;

    cin >> C >> N;

    LRUCache obj(C);

    for (int i = 0; i < N; i++) {

        string command;
        cin >> command;

        if (command == "FETCH") {

            int chunk_id;
            cin >> chunk_id;

            obj.fetch(chunk_id);
        }

        else if (command == "STATUS") {

            obj.status();
        }
    }

    return 0;
}