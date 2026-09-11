
#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    queue<int> q1;
    queue<int> q2;

    // Push element into stack
    void push(int val) {

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Insert new element into q1
        q1.push(val);

        // Move elements back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();   // Important
        }
    }

    // Remove top element
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        q1.pop();
    }

    // Return top element
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return q1.front();
    }

    // Check if stack is empty
    bool empty() {
        return q1.empty();
    }

    // Display stack
    void display() {
        queue<int> temp = q1;

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main() {
// class-object;
    Stack st;

    st.push(23);
    st.push(12);
    st.push(89);

    cout << "Stack: ";
    st.display();

    cout << "Top: " << st.top() << endl;

    st.pop();

    cout << "After pop: ";
    st.display();

    cout << "Top: " << st.top() << endl;

    cout << "Is stack empty? "
         << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}

