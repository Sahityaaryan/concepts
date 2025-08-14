
#include<bits/stdc++.h>
using namespace std;


/*
    first of all-> can be used negative weights
    -> and you can also detect negative weight cycle
    -> multi source shortest path
    
    This algorithm works for both the directed and undirected weighted graphs
    and can handle graphs with both positive and negative weight edges.

    Note: It does not work for the graphs with negative cycles (where the sum of the 
    edges in a cycle is negative).
    
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
#define vb vector<bool>
#define ima INT_MAX
#define imi INT_MIN

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int max_node = 1e8;
        int row = sz(dist), col = sz(dist[0]);
        int V = max(row, col);
        for(int via = 0; via < row;++via){
            for(int u = 0; u < row; ++u){
                for(int v = 0; v < col; ++v){
                  if(dist[u][via]!=1e8 && dist[via][v]!=1e8)  dist[u][v] = min(dist[u][v], dist[u][via]+dist[via][v]);
                }
            }
        }
    }
};

int main(){

    return 0;
}