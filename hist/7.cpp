#include<bits/stdc++.h>
using namespace std;

/*
 *
 * leetcode (233) :-> https://leetcode.com/problems/number-of-digit-one/
 *
 *
 *
 */

int sol(int pos, bool tight, int curr, string& num, vector<vector<vector<int>>>& dp){
    if(pos == num.length()) return curr;

    int limit = tight ? num[pos]-'0': 9;
    int no_of_1_digit_in_number = 0;

    for(int digit = 0; digit <= limit; ++digit){
        int newTight = tight && (digit == limit); // here we are posing newtight like if we are choosing anything from 0-9 then the tight will be
        // false because we can go to every possible digit but as the digit hits it's original limit and tight is also true like now we have to carefully
        // choose the digit
        int newCurr = curr + (digit == 1); // here we are doing this because we have to count the number of 1 digit
        no_of_1_digit_in_number += sol(pos+1,newTight, newCurr, num, dp);
    }

    return dp[pos][tight][curr] = no_of_1_digit_in_number;

}

int countDigitOne(int n) {

    vector<vector<vector<int>>> dp(11, vector<vector<int>>(1, vector<int>(11, -1)));
        string num = to_string(n);
        return sol(0, true, 0, num, dp);
    }

int main(){

    return 0;
}




/*
 *
 *
 * string num;
     int dp[12][2][12];

     int fun(int pos, bool tight, int curr) {
         if (pos == num.size()) return curr;
         if(dp[pos][tight][curr] != -1) return dp[pos][tight][curr];
         int limit = tight ? num[pos] - '0' : 9;
         int ans = 0;

         for (int d = 0; d <= limit; ++d) {
             bool newTight = tight && (d == limit);
             int newcurr = curr + (d==1);
             ans += fun(pos + 1, newTight, newcurr);
         }
         return dp[pos][tight][curr] = ans;
     }

     int countDigitOne(int n) {
         num = to_string(n);
         memset(dp, -1, sizeof(dp));
         return fun(0, true, 0);
     }
 */
