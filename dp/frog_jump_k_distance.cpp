#include<bits/stdc++.h>
using namespace std;

int frogJump(vector<int>& heights, int k) {
        
    int n = heights.size();
    vector<int> dp(n,0);
    
    dp[0] = 0;
    
    if(n > 1) dp[1] = abs(heights[0] - heights[1]);
    
    
    for(int i = 2; i < n; i++){

        int min_steps = INT_MAX;

        int p = i-1;

        while(p >= 0 && p >= i-k){
            min_steps = min(min_steps, (abs(heights[i] - heights[p]) + dp[p]));
            p--;
        }

        dp[i] = min_steps;
    }
    
    return dp[n-1];
    }

int main(){
    
 cout << endl;
return 0;
}