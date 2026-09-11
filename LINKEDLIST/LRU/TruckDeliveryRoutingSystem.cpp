#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;        // locationId
    int val;        // packageCount

    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};


class TruckDeliverySystem {

private:
//declaration;
    unordered_map<int, Node*> mpp;

    Node* head;


public:
//contructor;
    TruckDeliverySystem() {
        head = NULL;
    }


    // ADD location
    void add(int locationId, int packageCount) {

        // If location already exists
        if (mpp.find(locationId) != mpp.end()) {

            Node* node = mpp[locationId];

            node->val = packageCount;

            return;
        }

        // Create new node
        Node* newNode = new Node(locationId, packageCount);

        // If list is empty
        if (head == NULL) {

            head = newNode;

            newNode->next = newNode;
            newNode->prev = newNode;

        }
        else {

            // Last node
            Node* tail = head->prev;

            // Connect new node
            newNode->next = head;
            newNode->prev = tail;

            // Connect old tail
            tail->next = newNode;

            // Connect head
            head->prev = newNode;
        }

        // Add to map
        mpp[locationId] = newNode;
    }


    // REMOVE location
    void remove(int locationId) {

        if (mpp.find(locationId) == mpp.end()) {
            return;
        }

        Node* node = mpp[locationId];

        // Only one node
        if (node->next == node) {

            head = NULL;

        }
        else {

            node->prev->next = node->next;
            node->next->prev = node->prev;

            // If removing head
            if (node == head) {
                head = node->next;
            }
        }

        mpp.erase(locationId);

        delete node;
    }


    // NEXT location
    void nextLocation(int locationId) {

        if (mpp.find(locationId) == mpp.end()) {

            cout << -1 << endl;
            return;
        }

        Node* node = mpp[locationId];

        cout << node->next->key << endl;
    }


    // PREVIOUS location
    void prevLocation(int locationId) {

        if (mpp.find(locationId) == mpp.end()) {

            cout << -1 << endl;
            return;
        }

        Node* node = mpp[locationId];

        cout << node->prev->key << endl;
    }


    // DELIVER packages
    void deliver(int locationId) {

        if (mpp.find(locationId) == mpp.end()) {

            cout << -1 << endl;
            return;
        }

        Node* node = mpp[locationId];

        cout << node->val << endl;

        // Packages delivered
        node->val = 0;
    }


    // STATUS
    void status() {

        if (head == NULL) {

            cout << "EMPTY" << endl;
            return;
        }

        Node* curr = head;

        do {

            cout << curr->key;

            curr = curr->next;

            if (curr != head) {
                cout << " ";
            }

        } while (curr != head);

        cout << endl;
    }
};


int main() {

    int N;

    cin >> N;

    TruckDeliverySystem obj;


    while (N--) {

        string command;

        cin >> command;


        if (command == "ADD") {

            int locationId;
            int packageCount;

            cin >> locationId >> packageCount;

            obj.add(locationId, packageCount);
        }


        else if (command == "REMOVE") {

            int locationId;

            cin >> locationId;

            obj.remove(locationId);
        }


        else if (command == "NEXT") {

            int locationId;

            cin >> locationId;

            obj.nextLocation(locationId);
        }


        else if (command == "PREV") {

            int locationId;

            cin >> locationId;

            obj.prevLocation(locationId);
        }


        else if (command == "DELIVER") {

            int locationId;

            cin >> locationId;

            obj.deliver(locationId);
        }


        else if (command == "STATUS") {

            obj.status();
        }
    }


    return 0;
}