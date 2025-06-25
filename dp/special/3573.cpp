#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll f(int i, int status, int rem_trans, vector<int>& pr, vector<vector<vector<ll>>>& dp){
    int n = pr.size();
    // base case
    // no transaction left

    if(rem_trans == 0) return 0;

    // 2. last day: close all transactions

    if( i == n-1){
        if(status == 0) return 0;
        if(status == 1) return pr[i];
        return -pr[i];
    }

    // Already calculated

    if(dp[i][status][rem_trans] != -1){
        return dp[i][status][rem_trans];
    }

    // try all possibilities

    ll ans = INT_MIN;

    // 1. Do Nothing
    ans = max(ans, f(i+1, status, rem_trans, pr, dp));

    if(status == 0){ // previously nothing done

        // buy
        ans = max(ans, -pr[i] + f(i+1, 1, rem_trans, pr, dp));
        // sell
        ans  = max(ans, pr[i] + f(i+1,2, rem_trans, pr,dp));
    } else if(status == 1){ // previously bought
        // sell
        ans  = max(ans, pr[i] + f(i+1,0, rem_trans-1, pr,dp));
    } else { // previously sold
        // buy
        ans = max(ans, -pr[i] + f(i+1, 0, rem_trans-1, pr, dp));
    }

    return dp[i][status][rem_trans] = ans;
}


ll maximumProfit(vector<int>& prices, int k) {
    int n = prices.size();

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(3, vector<ll>(k+1, -1)));

    return f(0,0,k,prices,dp);
}





int main(){

    return 0;
}
