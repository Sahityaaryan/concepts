
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


/*
 *
 *
 * GFG => Print all LCS sequences (https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1)
 *
 * here my answer wa scorrect but it was slow method of doing so
 *
 * here what is the fast method is to navigate to only those paths which contributes to the longest common subsequence
 */



class Solution {
  public:

    vector<string> allLCS(string &s1, string &s2) {
        vector<vector<set<string>>> dp(ln(s1)+1, vector<set<string>>(ln(s2)+1));
        int max_size = 0;
        // vector<string> ans;

        vvi dpp(ln(s1)+1, vi(ln(s2)+1,0));

        for(int i = 1; i <= ln(s1); ++i){
            for(int j = 1; j <= ln(s2); ++j){
                if(s1[i-1] == s2[j-1]) dpp[i][j] = 1+dpp[i-1][j-1];
                else dpp[i][j] = max(dpp[i-1][j], dpp[i][j-1]);
            }
        }


        auto st = sol(ln(s1),ln(s2),s1,s2, dp,dpp);

        return vector<string>(all(st));
    }

    private:
        set<string> sol(int i, int j, string &s1, string &s2, vector<vector<set<string>>> &dp, vvi &dpp) {
        if (i == 0 || j == 0) return {""};
        if (!dp[i][j].empty()) return dp[i][j];


            set<string> res;


            if(s1[i-1] == s2[j-1]){
                auto l1 = sol(i-1,j-1,s1,s2,dp,dpp);
                for(auto &r:l1){
                    res.insert(r+s1[i-1]);
                }
            } else {
                if(dpp[i-1][j] >= dpp[i][j-1]){
                    auto l2 = sol(i-1,j,s1,s2,dp,dpp);
                    res.insert(all(l2));
                }

                if(dpp[i-1][j] <= dpp[i][j-1]){
                    auto l3 = sol(i, j-1, s1,s2,dp,dpp);
                    res.insert(all(l3));
                }
            }

            return dp[i][j] = res;
        }
};



int main(){

    return 0;
}
