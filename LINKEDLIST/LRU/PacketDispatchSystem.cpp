// size=3 input size=9
// ADD 101 500
// ADD 102 600
// ADD 103 700
// GET 101
// STATUS
// ADD 104 800
// DISPATCH
// STATUS

#include <bits/stdc++.h>
using namespace std;


// Node of Doubly Linked List
class Node {
public:
    int key;       // packetId
    int val;       // data

    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};


class PacketDispatchSystem {

private:

    int capacity;

    // packetId -> Node address
    unordered_map<int, Node*> mpp;

    // Dummy nodes
    Node* head;
    Node* tail;


public:

    // Constructor
    PacketDispatchSystem(int c) {

        capacity = c;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        // Connect head and tail
        head->next = tail;
        tail->prev = head;
    }


    // Remove a node from the linked list
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


    // ADD operation
    void add(int packetId, int data) {

        // Packet already exists
        if (mpp.find(packetId) != mpp.end()) {

            Node* node = mpp[packetId];

            // Update data
            node->val = data;

            // Move to front
            deleteNode(node);
            insert(node);

            return;
        }


        // Storage is full
        if (mpp.size() == capacity) {

            // Least Recently Used packet
            Node* lru = tail->prev;

            // Remove from HashMap
            mpp.erase(lru->key);

            // Remove from linked list
            deleteNode(lru);

            // Free memory
            delete lru;
        }


        // Create new packet
        Node* newNode = new Node(packetId, data);

        // Add to HashMap
        mpp[packetId] = newNode;

        // Add to front
        insert(newNode);
    }


    // GET operation
    int get(int packetId) {

        // Packet doesn't exist
        if (mpp.find(packetId) == mpp.end()) {
            return -1;
        }

        Node* node = mpp[packetId];

        // Accessed packet becomes MRU
        deleteNode(node);
        insert(node);

        return node->val;
    }


    // DISPATCH operation
    int dispatch() {

        // No packets
        if (mpp.empty()) {
            return -1;
        }

        // LRU packet
        Node* lru = tail->prev;

        int packetId = lru->key;

        // Remove from HashMap
        mpp.erase(packetId);

        // Remove from linked list
        deleteNode(lru);

        // Free memory
        delete lru;

        return packetId;
    }


    // STATUS operation
    void status() {

        Node* curr = head->next;

        // No packets
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

    // C = capacity
    // N = number of operations
    cin >> C >> N;

    PacketDispatchSystem obj(C);


    while (N--) {

        string command;

        cin >> command;


        // ADD packetId data
        if (command == "ADD") {

            int packetId;
            int data;

            cin >> packetId >> data;

            obj.add(packetId, data);
        }


        // GET packetId
        else if (command == "GET") {

            int packetId;

            cin >> packetId;

            cout << obj.get(packetId) << endl;
        }


        // DISPATCH
        else if (command == "DISPATCH") {

            cout << obj.dispatch() << endl;
        }


        // STATUS
        else if (command == "STATUS") {

            obj.status();
        }
    }

    return 0;
}
