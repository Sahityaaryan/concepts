#include<bits/stdc++.h>
using namespace std;

string postToInfix(string exp) {
        

    // * Direct modifying the top is faster then one pop and one push operation 
        
        stack<string> st;
        
        for(char ch:exp){
            
            if(isalpha(ch) || isdigit(ch)){
                string str = "";
                str += ch;
                st.push(str);
            } else {
                string second = st.top();
                st.pop();
                st.top() = '(' + st.top();
                st.top() += ch;
                st.top() += second;
                st.top() += ')';
            }
        }
        
        return st.top();
    }

int main()
{

  string exp = "ab*c+";

  cout << "\nInfix: " << postToInfix(exp);
  
  cout << endl;
  return 0;
}