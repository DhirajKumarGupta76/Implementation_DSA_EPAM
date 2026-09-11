# include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};
node* head=NULL;
void insetAtEnd(int val){
    node* newnode=new node();
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL){
       
        head=newnode;
        return;
    }
   

    node*tail=head;
    while(tail->next!=NULL){
        tail=tail->next;

    }
    tail->next=newnode;
    newnode->prev=tail;
    
}
void print(){
    node* temp= head;
    cout << "NULL <-";
    while(temp!=NULL){
        cout<<temp->data<<"  <->";
        temp = temp->next;
    }
    cout << "NULL";
}

int main(){
    insetAtEnd(32);
    insetAtEnd(56);
    insetAtEnd(82);

    print();

    return 0;
}