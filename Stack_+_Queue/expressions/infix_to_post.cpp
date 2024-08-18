#include <bits/stdc++.h>
using namespace std;
    
int prior(char ch)
{

    switch (ch)
    {

    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default: // ch == '('
        return 0;
    }
}

string infixToPostfix(string s)
{

    stack<char> st;

    string ans = "";

    for (char ch : s)
    {
        if (isdigit(ch) || isalpha(ch))
        {
            ans += ch;
        }
        else
        {
            if (ch == '(')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                while (st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                    while (!st.empty() && prior(st.top()) >= prior(ch))
                    {
                        ans += st.top();
                        st.pop();
                    }
                st.push(ch);
            }
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infixToPostfix(infix);

    cout << "ans: " << postfix << endl;

    cout << endl;
    return 0;
}