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

// Function to find length of linked list
int findLength() {
    Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Print linked list
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

    cout << "Linked List: ";
    printList();

    cout << "Length of Linked List = " << findLength() << endl;

    return 0;
}