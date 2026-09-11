#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    stack<int> st;

public:
    void push(int x)
    {
        st.push(x);
    }

    int pop()
    {
        int x = st.top();
        st.pop();
        return x;
    }

    int evaluate(string exp)
    {
        stringstream ss(exp);
        string token;

        while(ss >> token)
        {
            // Number
            if(isdigit(token[0]))
            {
                push(stoi(token));
            }
            // Operator
            else
            {
                int b = pop();
                int a = pop();

                if(token == "+")
                    push(a + b);

                else if(token == "-")
                    push(a - b);

                else if(token == "*")
                    push(a * b);

                else if(token == "/")
                    push(a / b);

                else if(token == "%")
                    push(a % b);

                else if(token == "^")
                    push(pow(a, b));
            }
        }

        return pop();
    }
};

int main()
{
    string exp;

    cout << "Enter Postfix Expression:\n";
    getline(cin, exp);

    Solution obj;

    cout << "Answer = " << obj.evaluate(exp);

    return 0;
}