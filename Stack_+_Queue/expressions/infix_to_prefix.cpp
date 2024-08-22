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


string reverseInfix(string s){

  string ans = "";

  for(int i = s.length(); i >= 0; i--){

    char ch = s[i];

    if(ch == ')'){
      ans += '(';

    } else if(ch =='('){
      ans += ')';
    } else {
      ans += ch;
    }
  }

  return ans;

}

string infixToPostfix_without_removing_same_priority_operators(string s)
{

    stack<char> st;

    string ans = "";

    for (char ch : s)
    {

      if(ch == ' ') continue;

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
                    while (!st.empty() && prior(st.top()) > prior(ch))
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


string infixToPrefix(string s){
    s = reverseInfix(s);
    s = infixToPostfix_without_removing_same_priority_operators(s);
    // cout << "converted: " << s << endl;
    s = reverseInfix(s);

    return s;
}

int main()
{
    // string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string infix = "(A + B) * C- D + F";
    string prefix = infixToPrefix(infix);


    cout << "\nans: " << prefix << endl;

    cout << endl;
    return 0;
}