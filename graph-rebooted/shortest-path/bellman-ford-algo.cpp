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
#define vb vector<bool>
#define ima INT_MAX
#define imi INT_MIN

/*
    there are few things i want to write for the bellmand ford algor
    
    1. Needs only DAG
    2. can work on both the negative and the positive weights
    
    # limitations of dijkstra
    1. can't work with -ve edges
    2. can't detect -ve weight cycles
    
    Questions: why dijkstra fails with -ve edges?
    -> because it assumes that "If a node u has been visited then dist[u] is the
    shortes possible distance to u".
    
    -> but due to presence of -ve edges, a shorter path to an already visited node 
    might exist later.
    
    Questions: why dijkstra fails with -ve weight cycles?
    -> as it assumes finite shortest paths and that each node will be visited only
    once - so it can't detect or handle such cycles
    
    -> It may enter an infinite loop or produce incorrect distances.

    
    
    Questions: what is negative weight cycle?
    -> Such a cycle in a graph in which the sum of the edge weights is negative
    
    Questions: why the negative weight cycle is a problem for shortest path?
    -> If a graph has a negative weight cycle, the concept of a "shortes path" breaks
    down because you can keep going around that cycle indefinitely, reducing the
    path cost further each time. There will be no well-defined shortest path
    exists to the nodes reachable through that cycle.
    
*/

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        int max_dist = 1e8;
        vi dist(V,max_dist);
        
        // relaxing of nodes
        dist[src] = 0;
        
        for(int i = 0; i < V; ++i){
            for(auto edge:edges){
                int u = edge[0], v = edge[1], weight = edge[2];
                if(dist[u] != max_dist){
                    if(dist[v] > dist[u]+weight) {
                        dist[v] = dist[u]+weight;
                    }
                }
            }
        }
        
        // now checking for negative weight cycle  :-> we will again
        // run a cycle and if there exist a negative weight cycle
        // we can still find some shortest path for couple of nodes
        
        
        for(auto edge:edges){
            int u = edge[0], v = edge[1], weight = edge[2];
            if(dist[u] != max_dist){
                if(dist[v] > dist[u]+weight) return {-1};
            }
        }
        
        return dist;
    }
};


int main(){

    return 0;
}