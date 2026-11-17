#include<iostream>
# include<vector>
using namespace std;
struct listNode{
    int data;
    listNode* next;
    listNode(int val){
        data=val;
        next=NULL;
    }

};
listNode* buildNode(int n){
        if(n==0) return NULL;
        int x;
        cin>>x;
        listNode* head=new listNode(x);
        listNode* temp=head;
        vector<listNode*>node;
        node.push_back(head);
        for(int i=1;i<n;i++){
            int x;
            cin>>x;
            listNode* newnode=new listNode(x);
            node.push_back(newnode);
            temp->next=newnode;
            temp=temp->next;
        }
        if(n>1){
            temp->next=node[1];
        }
        return head;
        
    }
 class solution{
    public:
    listNode* StartNodeOfCycledLinkedList(listNode* head){
        if(head==NULL){
            return NULL;
        }
        listNode* slow=head;
        listNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                listNode* entry=head;
                while(slow!=entry){
                    slow=slow->next;
                    entry=entry->next;

                }
                return entry;

            }
        }
        // No cycle found
        return NULL;

    }
 };

int main(){
    int n;
    cin>>n;
    
   listNode* head=buildNode(n);
   solution obj;
   listNode* StartNode=obj.StartNodeOfCycledLinkedList(head);
    if (StartNode != NULL) {
        cout << "Cycle starts at node: " << StartNode->data << endl;
    }
    else {
        cout << "No cycle found" << endl;
    }
    return 0;
}