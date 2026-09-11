#include <bits/stdc++.h>
using namespace std;

// Node of the Doubly Linked List
class Node {
public:
    int key;
    int value;

    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
    int capacity;

    // Map stores:
    // key -> address of the corresponding node
    unordered_map<int, Node*> mp;

    // Dummy nodes
    // head->next = Most Recently Used (MRU)
    // tail->prev = Least Recently Used (LRU)
    Node* head;
    Node* tail;

public:

    // Constructor
    LRUCache(int c) {
        capacity = c;

        // Create dummy head and tail
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        // Initially list is empty
        head->next = tail;
        tail->prev = head;
    }

    // --------------------------------------------------
    // Remove a node from its current position
    // --------------------------------------------------
    void removeNode(Node* node) {

        Node* previous = node->prev;
        Node* nextNode = node->next;

        previous->next = nextNode;
        nextNode->prev = previous;
    }

    // --------------------------------------------------
    // Insert a node just after head
    // This means it becomes MOST RECENTLY USED
    // --------------------------------------------------
    void insertAtFront(Node* node) {

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // --------------------------------------------------
    // GET operation
    // --------------------------------------------------
    int get(int key) {

        // Key does not exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Get the node from map
        Node* node = mp[key];

        // Since it was accessed,
        // it becomes Most Recently Used.
        removeNode(node);
        insertAtFront(node);

        return node->value;
    }

    // --------------------------------------------------
    // PUT operation
    // --------------------------------------------------
    void put(int key, int value) {

        // ---------------------------------------------
        // CASE 1: Key already exists
        // ---------------------------------------------
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            // Update its value
            node->value = value;

            // Move it to the front because
            // it is now the Most Recently Used
            removeNode(node);
            insertAtFront(node);

            return;
        }

        // ---------------------------------------------
        // CASE 2: Key does not exist
        // ---------------------------------------------

        // If cache is full
        if (mp.size() == capacity) {

            // The node just before tail
            // is the Least Recently Used node
            Node* lru = tail->prev;

            // Remove it from the map
            mp.erase(lru->key);

            // Remove it from linked list
            removeNode(lru);

            // Free memory
            delete lru;
        }

        // Create a new node
        Node* newNode = new Node(key, value);

        // Store it in map
        mp[key] = newNode;

        // New node becomes Most Recently Used
        insertAtFront(newNode);
    }

    // --------------------------------------------------
    // Display cache from MRU -> LRU
    // --------------------------------------------------
    void display() {

        Node* current = head->next;

        while (current != tail) {
            cout << current->key << " ";
            current = current->next;
        }

        cout << endl;
    }
};


int main() {

    // Cache can store maximum 3 elements
    // class -obj;
    LRUCache cache(3);

    // Add elements
    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);

    cout << "Cache (MRU -> LRU): ";
    cache.display();

    // Access key 1
    // 1 becomes Most Recently Used
    cache.get(1);

    cout << "After get(1): ";
    cache.display();

    // Add key 4
    // Cache is full, so LRU element is removed
    cache.put(4, 400);

    cout << "After put(4): ";
    cache.display();

    // Try to get removed key
    cout << "get(2): " << cache.get(2) << endl;

    return 0;
}