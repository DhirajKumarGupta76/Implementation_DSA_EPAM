#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};

int main(){

    node* head=new node();
    node* second=new node();
    node* third=new node();

    head->data=10;
    second->data=20;
    third->data=30;

    head->next=second;
    second->next=third;
    third->next=NULL;

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }

    return 0;
}