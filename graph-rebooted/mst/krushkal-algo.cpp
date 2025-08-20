#include<bits/stdc++.h>
using namespace std;

// User function Template for C++


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

    Krushkal's algo

    1. Sort all the edges by their weight (we will first connect the minimum edges weight)
    
    2. Then we will check wheter these node are somehow connected or not, like if they have 
    already been connected this means we have already used the min. weight so no need
    to consider it again.
    

*/

class DSU {
    public:
    vi parent;
    
    DSU(int V){
        parent.resize(V,-1);    
    }
    
    int findParent(int node){
        if(parent[node]<0) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void insert(int u, int v){
        int paru = findParent(u);
        int parv = findParent(v);
        
        if(parent[paru] <= parent[parv]){
            parent[paru] += parent[parv];
            parent[parv] = paru;
        } else {
            parent[parv] += parent[paru];
            parent[paru] = parv;
        }
    }
    
    bool areConnected(int u, int v){
        int paru = findParent(u);
        int parv = findParent(v);
        
        return (paru == parv);
    }
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        
        DSU* dsu = new DSU(V);
        
        sort(all(edges), [](const vi& a, const vi& b)->bool{
            return a[2] < b[2];
        });
        
        
        int MST = 0;
        
        for(auto edge:edges){
            int u = edge[0], v = edge[1], weight = edge[2];
            if(!dsu->areConnected(u,v)){
                dsu->insert(u,v);
                MST += weight;
            }
        }
        
        return MST;
    }
};


int main(){

    return 0;
}