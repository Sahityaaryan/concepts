#include<bits/stdc++.h>
using namespace std;
    int max(int first,int second){
        if(first > second){
            return first;
        } 
        return second;
    }
    
    int maxDepth(string s) {

        stack<char> st;

        int i = 0,ans = 0;

        while(i < s.length()){
            if(s[i]=='('){
                st.push(s[i]);
            } else if(s[i]==')'){
                ans = max(st.size(),ans);
                st.pop();
            }

            i++;
        }   
        return ans;
    }


    // second appraoch counter variable

int main()
{
 cout << "size: " << maxDepth("jaimatadi");
    
    cout << endl;
    return 0;
}