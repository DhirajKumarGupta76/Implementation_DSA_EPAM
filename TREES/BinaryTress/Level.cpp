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
void levelOrder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        int n = q.size();

        while (n--) {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }

        cout << endl;
    }
}

int main(){
    Node* root=NULL;
   root=buildtrees(root);
   
cout << "\nLevel Order Traversal:\n";
    levelOrder(root);

    return 0;
}