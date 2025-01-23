#include<bits/stdc++.h>
using namespace std;
 

// 200. Number of Islands

// It is based on some concepts of backtracking (returning whenever you know it won't further leads to any solution and manipulating the value or doing something so the already counted things won't change) and using recursion to go in all possible direction from a point

void dfs(vector<vector<char>>& adj, int j, int i){
        if(j >= adj[0].size() || j < 0 || i >= adj.size() || i < 0 || adj[i][j] == '0'){
            return;
        }

        adj[i][j] = '0';

        dfs(adj,j,i-1);
        dfs(adj,j,i+1);
        dfs(adj,j-1,i);
        dfs(adj,j+1,i);
    }
    
    int numIslands(vector<vector<char>>& grid) {

        int count = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid, j, i);
                }
            }
        }

        return count;
    }

int main(){
    
 cout << endl;
return 0;
}