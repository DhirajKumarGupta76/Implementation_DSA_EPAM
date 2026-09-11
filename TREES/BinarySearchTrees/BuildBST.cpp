// Test it with
// 50 30 70 20 40 60 80 -1


# include<iostream>
#include<bits/stdc++.h>

using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d){
        data=d;
        left=NULL;
        right=NULL;

    }

};
TreeNode* deleteNode(TreeNode* root,int key){
    if(root==NULL) return NULL;
    if(root->data==key){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;

        }

        //1 child
        // left child
        if(root->left!=NULL && root->right==NULL){
            TreeNode* temp=root->left;
            delete root;
            return temp;
        }

        // right child
        if(root->left==NULL && root->right!=NULL){
            TreeNode* temp=root->right;
            delete root;
            return temp;
        }

       // 2 children
if(root->left != NULL && root->right != NULL){

    // Maximum value from left subtree
    TreeNode* temp = root->left;

    while(temp->right != NULL){
        temp = temp->right;
    }

    // Replace root data with maximum value
    root->data = temp->data;

    // Delete the duplicate node
    //call to delete may be zero, one,two child
    root->left = deleteNode(root->left, temp->data);
    
}
    }


    if(root->data>key){
        root->left=deleteNode(root->left,key);
        return root;
    }
    else{
        root->right=deleteNode(root->right,key);
        return root;

    }
    return root;

}
void preorder(TreeNode* root) {

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

void inorder(TreeNode* root) {
    if (root == NULL)
        return;

    // Left
    inorder(root->left);

    // Root
    cout << root->data << " ";

    // Right
    inorder(root->right);
}
void postorder(TreeNode* root) {
    if (root == NULL)
        return;

    // Left
    postorder(root->left);

    // Right
    postorder(root->right);

    // Root
    cout << root->data << " ";
}


void LevelOfTraversal(TreeNode* root){
    if(root==NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        while(n--){
            TreeNode* temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                 q.push(temp->left);

            }
            if(temp->right!=NULL){
                q.push(temp->right);
            } 
        }
        cout<<endl;
    }
}



TreeNode* insertBst(TreeNode* root,int data){
    
    if(root==NULL){
        root=new TreeNode(data);
        return root;
    }
    if(data>root->data){
        //right part;
        root->right=insertBst(root->right,data);

    }
     else{
            root->left=insertBst(root->left,data);
        }
        return root;

}

TreeNode* buildBst(TreeNode* root){
   
    cout<<"Enter The data in BST"<<endl;
    int data;
    cin>>data;
    while(data!=-1){
       root= insertBst(root,data);
        cin>>data;
    }
    return root;


}
int main(){
    TreeNode* root=NULL;
    
   root= buildBst(root);
    cout<<"Level Of Traversal"<<endl;
    LevelOfTraversal(root);

    cout<<"Preorder Traversal"<<endl;
    preorder(root);
    cout<<endl<<"Inorder Taversal"<<endl;
    inorder(root);
    cout<<endl<<"Postorder Traversal"<<endl;
    postorder(root);

    cout<<endl<<"Delete a 20 from BST"<<endl;
     deleteNode(root,20);
     cout<<"Level Of Traversal"<<endl;
    LevelOfTraversal(root);

    return 0;
}