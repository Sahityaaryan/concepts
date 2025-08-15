#include<bits/stdc++.h>
using namespace std;

/*
 * gfg :-> https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
 *
 * 1. parent node method
 */


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
     bool isCycle(int V, vector<vector<int>>& edges) {
         // Code here
         vvi adj(V);
         for(auto edge:edges){
             int u=edge[0], v = edge[1];
             adj[u].pb(v);
             adj[v].pb(u);
         }

         vi isv(V,0);

         for(int i = 0; i < sz(adj); ++i){
             if(!isv[i]){
                 if(dfs(i,adj,isv,-1)) return true;
             }
         }

         return false;
     }
     private:
         bool dfs(int u, vvi& adj, vi& isv, int parent){
             isv[u]=1;
             
             for(int v:adj[u]){
                 if(!isv[v]){
                    if(dfs(v,adj,isv,u)) return 1;
                 } else if(v != parent) return true;
             }

             return 0;
         }
 };

int main(){

    return 0;
}
