#include<iostream>
using namespace std;

struct node{
    int data;
    node* prev;
    node* next;
};

node* head = NULL;

void insertBegin(int value){

    node* newNode = new node();
    newNode->data = value;

    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL){
        head->prev = newNode;
    }

    head = newNode;
}

void printList(){

    node* temp = head;
    cout<<"NULL <- ";

    while(temp != NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }

    cout<<"NULL";
}

int main(){

    insertBegin(30);
    insertBegin(20);
    insertBegin(10);

    printList();
}