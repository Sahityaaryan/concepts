#include<bits/stdc++.h>
using namespace std;
    #define ll long long

    const int MOD = 1000000007;

void recursionSorting(stack<int>& st, int n){
    
    if(st.empty()){
        st.push(n);
        return;
    }
    
    int k = st.top();
    
    st.pop();
    
    recursionSorting(st,k);
    
   if( n != -1){
       
        if(st.top() <= n){
        st.push(n);
    } else {
        
        stack<int> s;
        
        while(!st.empty() && st.top() > n){
            s.push(st.top());
            st.pop();
        }
        
        st.push(n);
        
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
    }
   }
   
}



    int countGoodNumbers(long long n) {

        int ans = 1;
        int res = 20;

        if(n%2){
            ans *= 5;
            n--;
        }

        n /= 2;

        while(n){

            if(n%2){
                ans = (int) (((ll)ans * (ll)res) % MOD);
                n--;
            }

            res = (int) (((ll)res * (ll)res) % MOD);
            n /= 2;
        }

        return ans;        
    }



int main()
{
    cout << "good num: " << countGoodNumbers(10);
    cout << endl;
    return 0;
}