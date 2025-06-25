#include<bits/stdc++.h>
using namespace std;

// User function template for C++

class Solution {
  public:
    // Function to return a list of lists of integers denoting the members
    // of strongly connected components in the given graph.

    void dfs(int u, vector<int> adj[], vector<int>& lo, vector<int>& disc,vector<bool>& vis, vector<bool>& svis, int& neigh, vector<int>& temp, vector<vector<int>>& main){
        vis[u] = true;
        svis[u] = true;


        for(int v:adj[u]){
            if(!vis[v]){
                disc[v] = disc[u] + 1;
                lo[v] = lo[u] + 1;
            } else if(svis[v]){
                if(disc[u] >= lo[v]){
                    lo[u] = min(lo[u], lo[v]);
                }
                return;
            }
        }

        //back-checking
        if(vis[neigh] && svis[neigh] && disc[u] >= lo[neigh]){
            lo[u] = min(lo[u], lo[neigh]);
        }

        neigh = u;

        temp.push_back(u);

        if(disc[u] == lo[u]){
            sort(begin(temp), end(temp));
            main.push_back(temp);
        }

        temp.clear();

        svis[u] = false;
    }
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        // code here

        vector<vector<int>> main;
        vector<int> lo(V,0), disc(V, 0), temp;
        vector<bool> vis(V), svis(V);
        int neigh = -1;
        dfs(0, adj,lo, disc, vis, svis, neigh,temp, main);

        return main;
    }
};

int main(){

    return 0;
}
