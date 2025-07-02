#include<bits/stdc++.h>
using namespace std;

/*
 * 3599 :-> https://leetcode.com/problems/partition-array-to-minimize-xor/description/
 *
 *
 */

int minXor(vector<int>& nums, int k) {
    int n = nums.size();

    // Step 1: Prefix XOR
    vector<int> pfix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pfix[i] = pfix[i - 1] ^ nums[i - 1];
    }

    // Step 2: Initialize DP
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
    for (int i = 0; i <= n; i++) {
        dp[i][1] = pfix[i];  // Base case
    }

    // Step 3: Fill DP table
    for (int parts = 2; parts <= k; parts++) {
        for (int end = parts; end <= n; end++) {
            for (int split = parts - 1; split < end; split++) {
                int segmentXOR = pfix[end] ^ pfix[split];
                int maxXOR = max(dp[split][parts - 1], segmentXOR);
                dp[end][parts] = min(dp[end][parts], maxXOR);
            }
        }
    }

    return dp[n][k];
}

int main(){

    return 0;
}
