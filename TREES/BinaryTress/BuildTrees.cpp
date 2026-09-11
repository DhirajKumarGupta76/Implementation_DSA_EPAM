#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }

};
//using recurrsion
Node* buildtrees(Node* root){
    cout<<"Enter The data:"<<endl;
    int data;
    cin>>data;
    if(data==-1) return NULL;
    root=new Node(data);
    
    cout<<"Enter the data in left of "<<data<<endl;
    root->left=buildtrees(root->left);
     cout<<"Enter the data in right of "<<data<<endl;
    root->right=buildtrees(root->right);
    return root;

}
  
int main(){
    Node* root=NULL;
   root=buildtrees(root);


    return 0;
}