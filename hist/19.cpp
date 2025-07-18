#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())
#define ll long long
#define F first
#define S second
#define ln(s) ((int)(s).length())
#define umci unordered_map<char, int>
#define umii unordered_map<int, int>
#define umsi unordered_map<string, int>
#define sst stringstream

/*

    leetcode (3407):-> https://leetcode.com/problems/substring-matching-pattern/

    here in this question if you want to know the maximum length matched
    substring with string s, you have to take care of a lot of edge cases

    1. if you found some equal chars:
        1.1 **Either this char is a start of the matched sbstring** :
                then we don't have to check whether the previous
                char was matching or not as we are starting to match the
                substring

        1.2 **or matched char in between the pattern** : so as we want
            max matched "substring" we have to ignore the in between
            matched char until the previous char is also matched
            as following the substring.

    2. if found the * then check for the max length when you don't include
    it at all, or if you include it

    3. if you are the end then there will be two cases
        3.1: Either the p attern matched till last char
        3.2 or the pattern end in matching in somewhere between
        so you have to maintain tha what's the maximum matching length
        you have got while traversing

*/

class Solution {
public:
    bool hasMatch(string s, string p) {
        int m = ln(p), n = ln(s);

        vvi dp(m+1,vi(n+1,0));
        dp[0][0]=1;
        for(int i = 1; i <= m; ++i){
            if(p[i-1]=='*') dp[i][0]=1;
            else break;
        }

            int max_found = 0;
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(p[i-1]==s[j-1]) {
                    if(i==1) dp[i][j] = 1+dp[i-1][j-1];
                    else {
                        if(dp[i-1][j-1] > 0) dp[i][j] = 1+dp[i-1][j-1];
                    }
                }
                else if(p[i-1]=='*') {
                   if(dp[i][j-1]>0 || dp[i-1][j]>0) dp[i][j] = max(dp[i-1][j], 1+dp[i][j-1]);
                }
                if(i==m) dp[i][j] = max(dp[i][j-1], dp[i][j]);
            }
        }

        return dp[m][n];
    }
};

int main(){

    return 0;
}
