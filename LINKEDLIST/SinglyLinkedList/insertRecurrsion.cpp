#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head = NULL;
void insert(int value){
   node* newNode = new node();
   newNode->data = value;
    if(head == NULL){    // linkedList is empty;
        head = newNode;
        return;
    }
    else{
        // newNode->data = value;
        newNode->next = head;
        
        head = newNode;
    }

}

int main(){
    // node* head;

    insert(23);
    insert(87);
    insert(98);

    node* temp = head;
     while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    return 0;
}
