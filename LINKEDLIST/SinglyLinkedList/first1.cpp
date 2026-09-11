#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* insertBegin(Node* head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;

    newNode->next = head;
    head = newNode;

    return head;
}

void printList(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* head = NULL;

    head = insertBegin(head, 30);
    head = insertBegin(head, 20);
    head = insertBegin(head, 10);

    printList(head);

    return 0;
}

