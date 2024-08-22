#include<bits/stdc++.h>
using namespace std;

 string preToInfix(string pre_exp) {
       stack<string> st;
        
        
        // top1 (operator) top2
        
        for(int i = pre_exp.length()-1; i>=0; i--){
            
            char ch = pre_exp[i];
            
            if(isalpha(ch) || isdigit(ch)){
                st.push(string(1,ch));
            } else {
                string top1 = st.top();
                st.pop();
                
                // st.top() == top2
                
                top1 = '(' + top1;
                top1 += ch;
                st.top() = top1 + st.top();
                st.top() += ')';
            }
        }
        
        return st.top();

    }

int main()
{
  // cout << string(3,'1'); // string(numberOfTimesToReapeatAChar, char)

  string exp = "*-A/BC-/AKL";

  cout << "\nInfix: " << preToInfix(exp);
  cout << endl;
  return 0;
}