#include <bits/stdc++.h>
using namespace std;

/*
    Kosaraju's algorithm:-> helps to find the number of strongly connected components within a directed graph.

    feel:-> Belows are the situations where the algo is used to understand the

    Dependency Resolution: In package management systems, SCCs can help resolve dependencies between packages, ensuring that all required packages are installed in the correct order.

    Circuit Design: In electronic circuit design, SCCs can be used to analyze feedback loops and optimize circuit performance.

    Database Query Optimization: In databases, understanding the dependencies between different queries can be modeled as a directed graph, where SCCs can help optimize query execution.
*/

void dfs(vector<vector<int>> &adj, int u, stack<int>& st, vector<bool>& isv){
      isv[u] = true;
    //   st.push(u); // if we push it here it will be arranged in hte order of start time
      for(int v:adj[u]){
          if(!isv[v]) dfs(adj, v, st, isv);
      }
      st.push(u); // pushing here is arranging it in the order of the end time
  }

  void dfsrec(vector<vector<int>> &adj, int u, vector<int>& t, vector<bool>& isv){
      isv[u] = true;

      for(int v:adj[u]){
          if(!isv[v]) dfsrec(adj, v, t, isv);
      }
      t.push_back(u);
  }

    int kosaraju(vector<vector<int>> &adj) {

        vector<vector<int>> connected_nodes;

        int n = adj.size();
        stack<int> st;

        vector<bool> isv(n,false);

        for(int i = 0; i < n; i++){
            if(!isv[i]) dfs(adj,i,st,isv);
        }

        vector<int> ftorder;
        while(!st.empty()){
            ftorder.push_back(st.top());st.pop();
        }

        // formation of transpose

        vector<vector<int>> trans_adj(n);

        for(int u = 0; u < n; u++){
            isv[u] = false;
            for(int v:adj[u]){
                trans_adj[v].push_back(u);
            }
        }


        for(int i:ftorder){
            if(!isv[i]){
                vector<int> t;
                dfsrec(trans_adj, i, t, isv);
                connected_nodes.push_back(t);
            }
        }

        return connected_nodes.size();
    }
int main(){

    return 0;
}
