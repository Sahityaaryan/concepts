#include<bits/stdc++.h>
using namespace std;
 

//  684. Redundant Connection



 /*
    This is an example of creating the graph on the go i am creating a graph by adding them to adjoining
    matrix if the nodes of the edges are not forming a loop and I am checking whether they are forming 
    a loop or not for every edges
*/
    bool dfs(unordered_map<int, vector<int>>& adj, int start, int end, vector<int>& vis) {
        vis[start] = true;
        for (auto& adjNode : adj[start]) {
            if (!vis[adjNode]) {
                if (adjNode == end || dfs(adj, adjNode, end, vis))
                    return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> res;
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            vector<int> vis(n + 1, false);
            if (dfs(adj, u, v, vis)) {
                res = {u, v};
            } else {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        return res;
    }


int main(){
    
 cout << endl;
return 0;
}