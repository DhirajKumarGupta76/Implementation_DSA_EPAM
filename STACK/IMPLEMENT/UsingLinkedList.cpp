
#include <bits/stdc++.h>
using namespace std;

class Stack {
public:

    // Node
    struct Node {
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
    };

    Node* topNode = NULL;

    // Push
    void push(int val) {
        Node* newNode = new Node(val);

        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop
    void pop() {
        if (topNode == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = topNode;
        topNode = topNode->next;

        delete temp;
    }

    // Top
    int top() {
        if (topNode == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return topNode->data;
    }

    // Empty
    bool empty() {
        return topNode == NULL;
    }
};

int main() {

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;

    st.pop();

    cout << "Top after pop: " << st.top() << endl;

    return 0;
}

