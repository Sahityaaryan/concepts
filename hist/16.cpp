
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
 *
 * Leetcode (1092) :-> https://leetcode.com/problems/shortest-common-supersequence/description/
 *
 * similar questions :-> 15.cpp , 2800
 *
 *
    this quesion is based upon an observation, while calculating the common sub
    we always take like this max(dp[i-1][j], dp[i][j-1]);

    because whosoever is providing less number of common subsequence we
    are not taking it in the longest common subseqeunce

    and that's why we are taking exactly those elements which were removed
    to get the maximum common subsequence like

    dp[i-1][j] > dp[i][j-1] -> it means that we get the longest subsequence
    after removing the ith character from the string so we add that character
    in our answer because that character is not included in the common subseqeuce

    1. one string which is a longest common subsequece => then consider the
        chars of only this block (s1[i-1] == s2[j-1])
    2. want string which is removed while calculating the common subseq =>
        add those chars which was giving the less common subsequence and
        those which we're not included in the comparision


    Note :-> but you can have subsequence only by traversing from the bottom
    right of the dp, because that's the only way you can get that okay
    which char had contributed to the final longest common subseqeuence


*/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vvi dp(ln(str1)+1, vi(ln(str2)+1, 0));

        for(int i = 1; i <= ln(str1); ++i){
            for(int j = 1; j <= ln(str2); ++j){
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int i = ln(str1), j = ln(str2);
        sst s;

        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                s << str1[i-1];
                i--;--j;
            } else if(dp[i][j-1] > dp[i-1][j]){
                // I am taking that element which is not giving me the maximum
                // subsequece because that can't be the part of my common
                // subsequence
                s << str2[j-1];
                j--;
            } else {
                s << str1[i-1];
                i--;
            }
        }


        while(i > 0){
            s << str1[i-1];i--;
        }
        while(j > 0){
            s << str2[j-1];j--;
        }
        string ans = s.str();
        reverse(all(ans)); // reversing because remember I was traversing
        // through the end
        return ans;
    }
};


int main(){

    return 0;
}
