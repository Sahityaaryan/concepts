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


class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n = sz(arr), max_ind = n, count = INT_MIN;
        if(n==1 || n==0) return arr;
        vi ans;
        vector<pair<int, int>> dp(n,{1,n});

        for(int i = n-1; i >= 0; --i){
            int subs = 0, ind = -1;
            for(int j = i+1; j < n; ++j){
                if(arr[j] > arr[i] && subs < dp[j].F){
                    subs = dp[j].F;
                    ind = j;
                }
            }
            dp[i].F += subs;
            if(ind != -1)dp[i].S = ind;
            if(count <= dp[i].F){
                count = dp[i].F;
                max_ind = i;
            }
        }
        ans.pb(arr[max_ind]);

        int i = max_ind;

        while(i < n){
            if(dp[i].S < n) ans.pb(arr[dp[i].S]);
            i = dp[i].S;
        }

        return ans;

    }
};

int main(){

    return 0;
}
