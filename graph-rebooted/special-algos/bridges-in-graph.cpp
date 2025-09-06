
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

        memset(adj, {}, n*sizeof(vector<int>));

        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        bool vis[n];
        memset(vis, 0, n);

        int tin[n];
        memset(tin, -1, n);
        int low[n];
        memset(low, -1, n);

        vector<vector<int>> bridges;

        dfs(0,-1,vis, adj, tin, low, bridges);


        return bridges;
    }

    private:
    int timer = 1;
    
    void dfs(int node, int parent, bool vis[], vector<int> adj[], int tin[], int low[], vector<vector<int>>& bridges){
        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++;

        for(int v:adj[node]){
            if(parent == v) continue;
            if(!vis[v]){
                dfs(v, node, vis, adj, tin, low, bridges);
                low[node]= min(low[v], low[node]);


                if(tin[node] < low[v]) bridges.push_back({v,node});
            } else {
                low[node] = min(low[v], low[node]);
            }
        }
    }
};


int main(){

    return 0;
}
