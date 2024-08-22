
#include<bits/stdc++.h>
using namespace std;

string postToPre(string post_exp) {
        
        stack<string> st;
      
    //   operator top2 top 1
        
        for(char ch:post_exp){
            
            if(isalpha(ch) || isdigit(ch)){
                st.push(string(1,ch));
            } else {
                
                string top1 = st.top();
                st.pop();
                
                st.top() = ch + st.top();
                st.top() += top1;
            }
        }
        
        return st.top();
    }

int main()
{
  
  cout << endl;
  return 0;
}