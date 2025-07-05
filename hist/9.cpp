#include<bits/stdc++.h>
using namespace std;

/*
 *
 * Leetcode (72) -> https://leetcode.com/problems/edit-distance/description/
 */


class Solution {
public:


        /* here the dp is actually saying one thing, min operation to make
        word1[:i] == word2[:j]

        1. replace -> i-1, j-1 -> replace karke dono ith and jth element equal ho gaye
        hai toh ab bachi hui strings (word1[:i-1], word2[:j-1]) ko kaise equal kare
        wo bhi min operations main

        2. delete -> i-1, j -> ith element do delte ho gaya ab ye dekho ki
            word1[:i-1] ko min operations main word2[:j] ke equal kaise kare

        3. insert -> i, j-1 -> insert karke toh tumne elements equal kar diye
        (remember bottom up main nayi operations aage ke side hoti hai like
        we have s1 = "h" and s2 = "r", so inserting 'r' in s1  will be like
        this s1 = "hr" ) but i toh abhi bhi wahi hai so word1[:i] ko min operations
        main word2[:j-1] ke equal kaise kare.

        lekin agar
        word1[i-1] == word2[j-1]

        then dono main toh koi operation karne ki zarrurat nhi hai to phir
        bs dekh log ki dono element ko nikal kar kitna min operations karna padta
        hai equal karne ke liye


        */

     int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));

        for(int i=0; i<=n1; i++)dp[i][0] = i; // word1[:i] ko empty string ke equal
        // karne ke liye 0 to ith element ko delete hi karna padega, yahi
        // is case ka min operation hai

        for(int j=0; j<=n2; j++)dp[0][j] = j; // word2[:j] ko empty string se match
        // karane ke liye 0 se jth elements tak ko empty string main insert
        // karna hi padega yahi iska min operation hai

        for(int i = 1; i <= n1; ++i){
            for(int j = 1; j <= n2; ++j){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[n1][n2];
     }
};


int main(){

    return 0;
}
