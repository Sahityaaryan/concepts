#include<bits/stdc++.h>
using namespace std;

    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        int mod = 1e9+7;

        vector<long long> preSum(n+1,0);
        vector<long long> prePrefix(n+2,0);

        for(int i = 0; i < n; ++i){
            preSum[i+1] = (preSum[i] + strength[i])%mod;
        }

        for(int i = 0; i <= n; ++i){
            prePrefix[i+1] = (prePrefix[i] + preSum[i])%mod;
        }

        vector<int> left(n,0);
        vector<int> right(n,n-1);

        stack<int> st;

        for(int i =0; i < n; ++i){
            while(!st.empty() && strength[st.top()] >= strength[i]){
                st.pop();
            }
            left[i] = st.empty() ? -1:st.top();
            st.push(i);
        }

        for(int i = n-1; i>=0; --i){
            while(!st.empty() && strength[st.top()] > strength[i]){
                st.pop();
            }
            right[i] = st.empty() ? n:st.top();
            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; ++i){
            ans += ((prePrefix[right[i]+1]) - prePrefix[i+1])*(i-left[i])%mod + mod - (prePrefix[i+1] - prePrefix[left[i]+1])*((right[i]-i)%mod)*strength[i];
            ans %= mod;
        }
        return (int) ans;
    }

int main(){

    return 0;
}
