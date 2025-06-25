#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dp[2001][2001];
    unordered_map<int, int> mp;

    bool sol(int i, vector<int>& stones, int pj){
        if(i == stones.size()-1) return true;
        if(i >= stones.size()) return false;
        if(dp[i][pj] != -1) return dp[i][pj];
        bool canCross = false;


        for(int step = -1; step < 2; step++){
            int nextStep = pj + step;
            if(nextStep > 0){
                int d = stones[i] + nextStep;
                if(mp[d])canCross = canCross || sol(mp[d], stones, nextStep);
            }
        }
        return dp[i][pj] = canCross;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++){
            mp[stones[i]] = i;
        }

        return sol(0, stones, 0);
    }
};

int main(){

    return 0;
}
