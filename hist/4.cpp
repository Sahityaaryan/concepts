#include<bits/stdc++.h>
using namespace std;

/**
 *
 * Problem :-> 1143 leetcode , https://leetcode.com/problems/longest-common-subsequence/
 *
 *
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();

        vector<vector<int>> dp(len1+1 , vector<int>(len2+1,0));

        for(int i = 1; i <= len1; ++i){
            for(int j = 1; j <= len2; ++j){
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1; // here if the characters are
                    // same then they definitely contribute to the longest subsequence
                    // so we have to look for the longest subsequence without
                    // considering both of them
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // here we know that
                    // none of the strings are same so we have to see their
                    // contribution of longest subsequence by inlcuding either
                    // of the characters
                }
            }
        }

        return dp[len1][len2];
    }
};


int main(){

    return 0;
}
