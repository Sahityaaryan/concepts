#include<bits/stdc++.h>
using namespace std;
 

/*
    1443. Minimum Time to Collect All Apples in a Tree

    Learning : I have learnt one thing that I need a lot of practice, in this question the answer was right in front of my eyes still my logic wasn't even touching it.
*/

    int dfs(vector<vector<int>>& adj,vector<bool>& hasApple, int v, int parent){
        int time = 0;

        for(int& child:adj[v]){
            if(child == parent) continue;

            int time_from_child = dfs(adj, hasApple, child, v);

            if(time_from_child > 0 || hasApple[child]){
                time += (time_from_child + 2);
            }
        }

        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
         

        vector<vector<int>> adj(n);

        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return dfs(adj, hasApple, 0, -1);
    }

int main(){
    
 cout << endl;
return 0;
}