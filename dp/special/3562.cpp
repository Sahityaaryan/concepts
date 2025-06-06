#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;


vector<int>dfs(int node, int discount_flag, vector<int>&present, vector<int>& future, int budget, unordered_map<int , vector<int>>& tree, vector<vector<vector<int>>>& dp){
    if(!dp[node][discount_flag].empty()){
        return dp[node][discount_flag];
    }

    vector<int> profit_dp(budget+1,0);

    // ------------- Option 1: Don't buy current node------------------

    vector<int> option1(budget+1,0);

    for(int &v:tree[node]){
        vector<int> child_profit = dfs(v,0, present, future, budget, tree, dp);
        vector<int> temp(budget+1,0);

        for(int i = 0; i <= budget; i++){
            for(int bud_allocated = 0; bud_allocated <= i; ++bud_allocated){
                temp[i] = max(temp[i], option1[bud_allocated] + child_profit[i-bud_allocated]);
            }
        }
        option1 = temp;
    }

    // ------------------- Option 2: Buy current node u -------------------

    int cost = discount_flag ? (present[node]/2):present[node];
    int profit_current = future[node]-cost;
    vector<int> option2_updated(budget+1, -1e9); // this will have the final profit of the parent node

    if(cost >= 0 && cost <= budget){
        vector<int> option2(budget+1,0); // calculating the max profit gained from every child if we spend i amount (explained in my copy)

        for(int& v:tree[node]){
            vector<int> child_profit = dfs(v, 1,present, future, budget, tree, dp);
            vector<int> temp(budget+1,0);
            for(int i = 0; i <= budget;i++){
                for(int bud_allocated = 0; bud_allocated <= i; ++bud_allocated){
                    temp[i] = max(temp[i], option2[bud_allocated] + child_profit[i-bud_allocated]);
                }
            }

            option2 = temp;
        }



        for(int b = cost; b <= budget;++b){
            option2_updated[b] = profit_current + option2[b-cost];
        }
    }


    // ----------------- Combine the best of both options -----------

    for(int b = 0; b<=budget; ++b){
        profit_dp[b] = max(option1[b], max(option2_updated[b],0));
    }

    dp[node][discount_flag] = profit_dp;
    return profit_dp;
}

int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
    unordered_map<int, vector<int>> tree;

    for(auto& h:hierarchy){
        int u = h[0]-1;
        int v = h[1]-1;
        tree[u].push_back(v);
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2)); // /

    vector<int> profits = dfs(0, 0, present, future, budget, tree, dp);

    int max_profit = 0;

    for(auto& profit: profits){
        max_profit = max(max_profit, profit);
    }

    return max_profit;
}


int main(){

    return 0;
}
