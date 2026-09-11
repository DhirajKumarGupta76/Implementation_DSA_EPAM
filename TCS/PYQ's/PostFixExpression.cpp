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
        for(char ch : exp)
        {
            if(isdigit(ch))
            {
                push(ch - '0');
            }
            else
            {
                int val2 = pop();
                int val1 = pop();

                if(ch == '+')
                    push(val1 + val2);

                else if(ch == '-')
                    push(val1 - val2);

                else if(ch == '*')
                    push(val1 * val2);

                else if(ch == '/')
                    push(val1 / val2);

                else if(ch == '%')
                    push(val1 % val2);

                else if(ch == '^')
                    push(pow(val1, val2));

                // switch(ch)
                // {
                //     case '+':
                //         push(val1 + val2);
                //         break;

                //     case '-':
                //         push(val1 - val2);
                //         break;

                //     case '*':
                //         push(val1 * val2);
                //         break;

                //     case '/':
                //         push(val1 / val2);
                //         break;

                //     case '%':
                //         push(val1 % val2);
                //         break;

                //     case '^':
                //         push(pow(val1, val2));
                //         break;
                // }
            }
        }

        return pop();
    }
};

int main()
{
    string exp;

    cout << "Enter Postfix Expression: ";
    cin >> exp;

    Solution obj;

    cout << "Answer = " << obj.evaluate(exp);

    return 0;
}