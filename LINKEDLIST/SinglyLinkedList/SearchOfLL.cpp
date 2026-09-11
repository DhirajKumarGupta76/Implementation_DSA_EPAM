#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBegin(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Search function
bool searchElement(int key) {

    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

// Print list
void printList() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {

    insertBegin(10);
    insertBegin(20);
    insertBegin(30);
    insertBegin(40);

    printList();

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    if (searchElement(key))
        cout << "Element Found";
    else
        cout << "Element Not Found";

    return 0;
}


// Recurrsive calls;


// bool search(Node* head, int key){

//     if(head == NULL)
//         return false;

//     if(head->data == key)
//         return true;

//     return search(head->next, key);
// }