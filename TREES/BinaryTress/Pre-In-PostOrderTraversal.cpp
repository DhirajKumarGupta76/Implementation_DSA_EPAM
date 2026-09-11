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

void preorder(Node* root) {

    // Base case
    if (root == NULL)
        return;

    // 1. Root
    cout << root->data << " ";

    // 2. Left
    preorder(root->left);

    // 3. Right
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    // Left
    inorder(root->left);

    // Root
    cout << root->data << " ";

    // Right
    inorder(root->right);
}
void postorder(Node* root) {
    if (root == NULL)
        return;

    // Left
    postorder(root->left);

    // Right
    postorder(root->right);

    // Root
    cout << root->data << " ";
}

int main(){
    Node* root=NULL;
   root=buildtrees(root);

cout << "\nLevel Order Traversal:\n";
    levelOrder(root);

cout << "Preorder Traversal: ";
    preorder(root);

 cout << "Inorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);
    
    return 0;
}