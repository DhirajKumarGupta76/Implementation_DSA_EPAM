#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    queue<int> q;

public:
    // Push element into stack
    void push(int x) {
        int n = q.size();

        q.push(x);

        // Move previous elements behind x
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Remove top element
    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow" << endl;
            return;
        }

        q.pop();
    }

    // Return top element
    int top() {
        if (q.empty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return q.front();
    }

    // Check if stack is empty
    bool empty() {
        return q.empty();
    }

    // Return stack size
    int size() {
        return q.size();
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

    st.push(40);

    cout << "Top: " << st.top() << endl;

    return 0;
}