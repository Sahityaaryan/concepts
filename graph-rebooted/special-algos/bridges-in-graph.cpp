
#include<bits/stdc++.h>
using namespace std;

/**
 * 
 * check the dsa copy for the graphs and notes or can also check this : https://www.youtube.com/watch?v=qrAub5z8FeA
 */

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;

        dfs(0,-1,vis, adj, tin, low, bridges);


        return bridges;
    }

    private:
    int timer = 0;
    
    void dfs(int node, int parent, vector<bool>& vis, vector<int> adj[], int tin[], int low[], vector<vector<int>>& bridges){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;

        for(auto it:adj[node]){
            if(it == parent) continue;
            if(!vis[it]) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);

                // check whether node---it is a bridge or not
                // oh now I got it, it's check to the it (next node)
                // the next node got to have a bigger tin time but
                // if they are connected then the low[next node] will
                // either be small or equal to the tin[node] but since
                // it is not then they are not a part of a cycle and  can't
                // be reached if disconnected
                if(low[it] > tin[node]) bridges.push_back({it, node});
            } else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
};


int main(){

    return 0;
}
