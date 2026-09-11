#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Push operation
    void push(int value) {
        if (top == 99) {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = value;
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }

        cout << "Popped: " << arr[top] << endl;
        top--;
    }

    // Peek operation
    int peek() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Display stack
    void display() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Stack: ";
    st.display();

    cout << "Top element: " << st.peek() << endl;

    st.pop();

    cout << "Stack after pop: ";
    st.display();

    return 0;
}
