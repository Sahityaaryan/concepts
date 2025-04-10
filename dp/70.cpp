#include<bits/stdc++.h>
using namespace std;

/*
    link :-> https://leetcode.com/problems/climbing-stairs/description/

    // awesome questions for dp

    but please don't waste your time over the factorial methods because sometimes the factorial will become too large that can't be hold in the "long long int"

*/

int climbStairs(int n) {
    vector<int> dp(n+1);

    dp[0] = dp[1] = 1;

    for(int i = 2;i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main(){
    
 cout << endl;
return 0;
}