//problem - https://www.interviewbit.com/problems/sliding-window-maximum/

#include<bits/stdc++.h>
using namespace std;





vector<int> slidingMaximum(const vector<int> &A, int B) {    
    int n1 = A.size();
    int lead = 0,lag=0;
    
    vector<int> ans;
    queue<int> q;
    
    q.push(A[lead++]);
    
    if(n1==1) return {q.front()};
    
    
    while(lead < n1)
    {
        if(A[lead]>q.front())
        {
            while(!q.empty()) q.pop();
            q.push(A[lead]);
        }
        else if(A[lead]>q.back())
        {
            int l = q.front();
            
            while(!q.empty()) q.pop();
            q.push(l);
            q.push(A[lead]);
        }
        else if(q.size()==1)
        {
            q.push(A[lead]);
        }
        
        if(lead-lag+1==B)
        {
            ans.push_back(q.front());
            
            if(A[lag]==q.front())
            {
                q.pop();
            }
            lag++;
        }
        
        
        lead++;
    }
    
    return ans;
    

    }



int main()
{
 queue<int> q;
 q.push(1);
 q.push(2);
 stack<int>st;

 st.push(1);
 st.push(2);

 cout << st.top();
 st.pop();
  cout << st.top();
//  int lead = 0,lag = 0,n
 
  cout << '\n';
    return 0;
}