#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Build Binary Tree using Queue
Node* buildTree() {

    int data;

    cout << "Enter root data: ";
    cin >> data;

    // If root is -1, tree is empty
    if (data == -1)
        return NULL;

    Node* root = new Node(data);

    // Queue is used for level-order construction
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node* temp = q.front();
        q.pop();

        // ---------------- LEFT CHILD ----------------
        cout << "Enter left of " << temp->data << ": ";
        cin >> data;

        if (data != -1) {
            temp->left = new Node(data);
            q.push(temp->left);
        }

        // ---------------- RIGHT CHILD ----------------
        cout << "Enter right of " << temp->data << ": ";
        cin >> data;

        if (data != -1) {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }

    return root;
}

// --------------------------------------------------
// PREORDER: Root -> Left -> Right
// --------------------------------------------------
void preorder(Node* root) {

    if (root == NULL)
        return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

// --------------------------------------------------
// INORDER: Left -> Root -> Right
// --------------------------------------------------
void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// --------------------------------------------------
// POSTORDER: Left -> Right -> Root
// --------------------------------------------------
void postorder(Node* root) {

    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}

// --------------------------------------------------
// LEVEL ORDER: Using Queue
// --------------------------------------------------
void levelOrder(Node* root) {

    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------
int main() {

    // Build the tree
    Node* root = buildTree();

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nLevel Order: ";
    levelOrder(root);

    cout << endl;

    return 0;
}