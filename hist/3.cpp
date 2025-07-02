#include<bits/stdc++.h>
using namespace std;


/**
 *          Problem :-> 115 (leetcode), https://leetcode.com/problems/distinct-subsequences/
 *
 *      how to think in bottom up dp
 *      1. you must remember bottom up dp and starts when your normal dp hits the basecase or it's starts from there where answer is confirmed
 *      2. then it moves ahead and tries to make a recurrence relation which will help achieving the final goal, like how this base case answer will contribute
 *         in the current state
 *
 *
 */

class Solution {
public:

/*

    Recursion Approach here I am simply counting number of subsequeces like the way
    they occur in the t.

    we are saying that

     if(s[i] == t[j]):-
        1. we can find the rest of the string except the jth element as a
            subsequence in the s string.
        2. we can find the entire string including the jth element as a
            subsequence in the s string

    if(s[i] != t[i]):
        1. means we can't inlcude the jth element in the subsequence and
            we have to search for the elements ahead of the ith element
            in the s string



    Note:-> this answer also maintaining the order of occurence
*/

    int sol(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(j >= t.length()) return 1;
        if(i >= s.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = sol(i+1,j+1,s, t, dp) + sol(i+1,j,s,t,dp);

        return dp[i][j] = sol(i+1,j,s,t,dp);
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));

        return sol(0,0,s,t,dp);
    }



    /*
        2. Bottom-Up approach

        learning:->

        here they are exactly doing what a bottom up dp should be doing like
        dp[len1][len2] = number of subsequences in s from 0 to len2-1 (s[:len2])
        which equal to t from 0 to len1-1 (t[:len1])

        My Problem was that:-> I was not able to figure out how to calculate the
        length of the subsequence, using bottom up approach.

        Probably i was searching for the wrong thing I was finding the common subsequence
        but this problem is of finding number of such subsequece which equals t in s


    */

        int numDistinct(string s, string t) {
            int slen = s.length(), tlen = t.length();

            vector<vector<unsigned int>> dp(tlen+1, vector<unsigned int>(slen+1, 0));

            for(int i = 0; i <= slen; ++i){
                dp[0][i] = 1;
            }

            for(int i = 1; i <= tlen; ++i){
                for(int j = 1; j <= slen; ++j){
                    if(t[i-1] == s[j-1]){
                        dp[i][j] = (dp[i-1][j-1] + dp[i][j-1]);
                    } else {
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }


            return dp[tlen][slen];
        }
};

int main(){

    return 0;
}
