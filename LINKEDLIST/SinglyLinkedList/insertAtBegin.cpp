#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

node* head = NULL;

void insertBegin(int value){
    
    node* newNode = new node(value);   // create new node
    newNode->data = value;        // store value
    newNode->next = head;         // point to previous head
    head = newNode;               // move head to new node
}

void printList(){
    
    node* temp = head;
     cout<<"Head<-";
    while(temp != NULL){
       
        cout << temp->data << " <-";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main(){

    insertBegin(23);
    insertBegin(45);
    insertBegin(67);

    printList();

    return 0;
}