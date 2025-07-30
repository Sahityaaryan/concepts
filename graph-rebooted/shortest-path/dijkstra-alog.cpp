
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

/*

    Dijkstra algorithm :-> https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

    like it's best described in this video -> https://www.youtube.com/watch?v=EFg3u_E6eHU&t=303s

    here are some points from my side

    1. we are marking those nodes on which we have confirmed the shortest path to reach to those
        nodes, I have used (isVisited) for this marking
    2. It only provides the minimum time to reach at a certain position from the source but never
        tells anything about the path taken so I have included a prev_nodes vector which will
        store the previous node visitd before visiting the current node so that we can trace back
        to get the shortest path as well

    3. when you arrive on a certain node then you should compute the current or temporary shortest
        path to visit the respective adjacent nodes and now we should move on with only that node
        which has got the shotest path from the current node among all the adjacent nodes

        #### Small correction in the third point
            However, in a priority queue-based implementation, we don’t always pick the "minimum neighbor" of the current node — instead:

    You maintain a global priority queue (min-heap) with all candidates for the next node to visit.

    You always process the node with the globally smallest known distance — not just the smallest among current node’s neighbors.

    # properties
    1. I can work on both (cyclic and non-cyclic graph whether directed or undirected) just you
        have to make sure the weight of each edge should be positive.

*/

class Solution {
  public:
  struct Compare {
    bool operator()(const vi& a, const vi& b) const {
        return a[0] > b[0]; // Min heap based on a[0]
    }
};
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pii> adj[V];
        vb isv(V,0);
        vi prev_nodes(V,-1);

        for(auto edge:edges){
            int u = edge[0], v = edge[1], cost = edge[2];
            adj[u].pb({v,cost});
            adj[v].pb({u,cost});
        }

        vi dist(V,INT_MAX);
        dist[src] = 0;

        priority_queue<vi, vector<vi>, Compare> min_h;

        min_h.push({0,src,-1}); // first state -> distance , second state -> node, third state -> previous node

        while(!min_h.empty()){
            int u = min_h.top()[1], prev = min_h.top()[2]; min_h.pop();
            if(isv[u]) continue;
            isv[u]=1;
            prev_nodes[u] = prev;

            for(auto edge:adj[u]){
                int v = edge.F, cost = edge.S;
                if(!isv[v]){
                    if(dist[v] > dist[u]+cost){
                        dist[v] = dist[u]+cost;
                        min_h.push({dist[v], v, u});
                    }
                }
            }
        }

        return dist;
    }
};

int main(){

    return 0;
}
