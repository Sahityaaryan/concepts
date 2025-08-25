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

    question :-> https://www.geeksforgeeks.org/problems/articulation-point-1/1
    
    solution  :-> https://www.youtube.com/watch?v=j1QDfU21iZk
    
    follow ups -> https://www.geeksforgeeks.org/problems/articulation-point2616/1

    articulation points -> those nodes whose removal will divide the graph into multiple components
*/

class Solution {
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        
        set<int> st;
        vb isv(V,0);
        vi low(V, ima);
        vi tin(V,-1);
        vector<pii> col;
        
        
        for(int i = 0; i < V; ++i){
            if(!isv[i]) {
                dfs(i,-1,adj,isv,low,tin,st);
            }
        }
        
        if(sz(st) == 0) return {-1};
        
       
        return vector<int>(all(st));
    }
    
    private:
    int timer = 0;
        void dfs(int node, int parent, vector<int> adj[], vector<bool>& isv,vi& low, vi& tin, set<int>& st){
            isv[node]=1;
            tin[node]=low[node]=timer;
            timer++;
            
            int child = 0;
            
            for(auto it:adj[node]){
                if(it == parent) continue;
                if(!isv[it]){
                    dfs(it, node, adj, isv, low, tin, st);
                    low[node]=min(low[node], low[it]);
                    child++;
                    
                    if(low[it] >= tin[node] && parent!=-1) { // means either the "it" can't reach
                    // any node which is before the node and even if it can react
                    // to the very node then also it's of no use because that
                    // node is going to be removed and yes we didn't count the starting
                    // node 
                        st.insert(node);
                    }
                } else {
                    low[node] = min(low[node], tin[it]);
                }
            }
            
            if(child > 1 && parent == -1) st.insert(node); // here it simply meant
            // that we only count those as a child which is the point which are not a part
            // of a single cycle because if they would they have been already be visited
            // if we apply dfs on any child 
        }
};


int main(){

    return 0;
}