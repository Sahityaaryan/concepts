#include<bits/stdc++.h>
using namespace std;

string preToPost(string pre_exp) {
        
        stack<string> st;
        // top1 + top2 + operator
        
        for(int i = pre_exp.length() - 1; i >= 0; i--){
            
            char ch = pre_exp[i];
            
            if(isalpha(ch) || isdigit(ch)){
                st.push(string(1,ch));
            } else {
                
                string top1 = st.top();
                st.pop();
                
                st.top() = top1 + st.top();
                st.top() += ch;
            }
        }
        
        return st.top();
    }

int main()
{
  
  cout << endl;
  return 0;
}