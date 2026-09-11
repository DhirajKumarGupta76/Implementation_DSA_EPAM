#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> st;      // Stack

public:

    // Push into stack
    void push(int x) {
        st.push_back(x);
    }

    // Pop from stack
    int pop() {
        int x = st.back();
        st.pop_back();
        return x;
    }

    int evaluate(int n) {

        vector<string> tokens(n);

        cout << "Enter postfix expression:\n";
        for (int i = 0; i < n; i++) {
            cin >> tokens[i];
        }

        for (int i = 0; i < n; i++) {

            if (tokens[i] == "+" ||
                tokens[i] == "-" ||
                tokens[i] == "*" ||
                tokens[i] == "/") {

                int b = pop();
                int a = pop();

                int ans;

                if (tokens[i] == "+")
                    ans = a + b;

                else if (tokens[i] == "-")
                    ans = a - b;

                else if (tokens[i] == "*")
                    ans = a * b;

                else
                    ans = a / b;

                push(ans);
            }
            else {

                // Convert string into integer
                push(stoi(tokens[i]));
            }
        }

        return pop();
    }
};

int main() {

    int n;

    cout << "Enter number of tokens: ";
    cin >> n;

    Solution obj;

    cout << "Answer = " << obj.evaluate(n);

    return 0;
}
