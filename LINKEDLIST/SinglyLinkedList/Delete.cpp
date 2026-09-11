#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head = NULL;

void insertBegin(int value){
    
    node* newNode = new node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void printList(){
    
    node* temp = head;
    
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

void deleteFirst(){

    if(head == NULL)
        return;

    node* temp = head;
    head = head->next;
    delete temp;
}

int main(){

    insertBegin(23);
    insertBegin(45);
    insertBegin(67);

    printList();

    deleteFirst();

    printList();

    return 0;
}