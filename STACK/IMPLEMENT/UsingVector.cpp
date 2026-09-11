#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    vector<int> st;

public:

    // Push element into stack
    void push(int value) {
        st.push_back(value);
    }

    // Remove top element
    void pop() {
        if (st.empty()) {
            cout << "Stack Underflow" << endl;
            return;
        }

        st.pop_back();
    }

    // Return top element
    int top() {
        if (st.empty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return st.back();
    }

    // Check whether stack is empty
    bool empty() {
        return st.empty();
    }

    // Return number of elements
    int size() {
        return st.size();
    }

    // Display stack
    void display() {
        if (st.empty()) {
            cout << "Stack is Empty" << endl;
            return;
        }

        for (int i = st.size() - 1; i >= 0; i--) {
            cout << st[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    Stack st;

    // Push
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Stack: ";
    st.display();

    // Top
    cout << "Top element: " << st.top() << endl;

    // Size
    cout << "Size: " << st.size() << endl;

    // Pop
    st.pop();

    cout << "After pop: ";
    st.display();

    cout << "Top element: " << st.top() << endl;

    // Empty
    if (st.empty()) {
        cout << "Stack is Empty" << endl;
    }
    else {
        cout << "Stack is Not Empty" << endl;
    }

    return 0;
}