#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// create new node
Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// insert at beginning
void insertBegin(int value){

    Node* newNode = createNode(value);

    if(head == NULL){
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// insert at end
void insertEnd(int value){

    Node* newNode = createNode(value);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// insert at specific position
void insertPosition(int value, int pos){

    Node* newNode = createNode(value);
    Node* temp = head;

    for(int i=1;i<pos-1;i++){
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL){
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// print list
void printList(){

    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

int main(){

    int choice,value,pos;

    while(true){

        cout<<"\n1.Insert Beginning\n";
        cout<<"2.Insert End\n";
        cout<<"3.Insert Position\n";
        cout<<"4.Display\n";
        cout<<"5.Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){

        case 1:
            cout<<"Enter value: ";
            cin>>value;
            insertBegin(value);
            break;

        case 2:
            cout<<"Enter value: ";
            cin>>value;
            insertEnd(value);
            break;

        case 3:
            cout<<"Enter value: ";
            cin>>value;
            cout<<"Enter position: ";
            cin>>pos;
            insertPosition(value,pos);
            break;

        case 4:
            printList();
            break;

        case 5:
            return 0;

        default:
            cout<<"Invalid choice";
        }
    }
}