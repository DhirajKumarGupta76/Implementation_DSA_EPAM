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

void insertAtEnd(int value){
    
    node* newNode = new node(value);   // create new node
    newNode->data = value;        // store value
    newNode->next = NULL; 
    
        // case 1: list is empty
    if(head == NULL){
        head = newNode;
        return;
    }
        
    node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }  
    tail->next=newNode;
    

}

void printList(){
    
    node* temp = head;
    cout<<"Head->";
    while(temp != NULL){
        cout << temp->data << " ->";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main(){
 
    insertAtEnd(23);
    insertAtEnd(45);
    insertAtEnd(67);

    printList();

    return 0;
}