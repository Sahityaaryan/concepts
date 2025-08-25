

#include<bits/stdc++.h>
using namespace std;

/*
    Link :-> https://www.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/1


    // here we are using tarjans algo of the articulation points
*/


// User function template for C++

class Solution {
  public:
    // Function to return a list of lists of integers denoting the members
    // of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        vector<vector<int>> ans;
        
        vector<int> disc(V), low(V);
        vector<bool> visited(V,0);
        
        stack<int> s;
        vector<bool> InStack(V,0);
        int timer = 0;
        
        for(int i = 0; i < V; ++i){
            if(!visited[i]) dfs(i, adj, visited, disc, low, s, InStack, ans, timer);
        }
        
        sort(begin(ans), end(ans));
        return ans;
    }
    
    private:
        void dfs(int node, vector<int> adj[], vector<bool>& visited, vector<int>& disc, vector<int>& low, stack<int>& s, vector<bool>& InStack, vector<vector<int>>& ans, int &timer){
            visited[node]=1;
            disc[node]=low[node]=timer;
            
            s.push(node);
            InStack[node]=1;
            
            for(int j = 0; j < adj[node].size(); ++j){
                int neib = adj[node][j];
                
                if(!visited[neib]) {
                    timer++;
                    dfs(neib, adj, visited, disc, low, s, InStack, ans, timer);
                    low[node] = min(low[node], low[neib]);
                } else {
                    if(InStack[neib]){
                        low[node] = min(low[node], disc[neib]);
                    }
                }
            }
            
            if(disc[node]==low[node]){
                    vector<int> temp;
                    while(!s.empty() && (s.top() != node)){
                        temp.push_back(s.top());
                        InStack[s.top()] = 0; s.pop();
                    }
                    temp.push_back(node);
                    InStack[node]=0;
                    s.pop();
                    
                    sort(begin(temp), end(temp));
                    ans.push_back(temp);
                }
        }
};


int main(){

    return 0;
}