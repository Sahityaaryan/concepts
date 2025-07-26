
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

/*

    shortest path in undirected-graph :-> https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1



 */

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V = sz(adj);

        vi dist(V, -1); // will store the shortest distance from the src (here -1 means there is no any path from src node to ith node)
        queue<int> q;

        q.push(src);
        dist[src] = 0;

        while(!q.empty()){
            int u = q.front(); q.pop();
            int dist_u = dist[u];

            for(int v:adj[u]){
                if((dist[v] > dist_u+1) || dist[v] == -1){
                    dist[v] = dist_u+1;
                    q.push(v);
                }
            }
        }

        return dist;
    }
};

int main(){

    return 0;
}
