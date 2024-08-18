#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
 vector<int> dailyTemperatures(vector<int>& temperatures) {
           int n = temperatures.size();
           vector<int> ans(n,0);
        

           stack<int>st;

           int i =n-1,j=0;

           while(i>=0){
               if(st.empty()){
                   st.push(i);
                    i--;
                   continue;
               }

            //    checking whether the stack has larger or not

            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
               st.pop();
            }

            if(st.empty()){
                ans[i]=0;
            } else {
                ans[i] =  st.top()-i;
            }
                st.push(i);
               i--;
           }

        return ans;
    }
};

int main()
{
 
    
    cout << endl;
    return 0;
}