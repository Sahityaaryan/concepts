#include<bits/stdc++.h>
using namespace std;
 

//  same backtracking concept

    int area(vector<vector<int>>& grid, int u, int v){
        if(u >= grid.size() || u < 0 || v >= grid[0].size() || v < 0) return 0;
        if(grid[u][v]==0) return 0;

        grid[u][v] = 0;

        return 1 + area(grid, u+1, v) + area(grid, u-1, v) + area(grid, u, v-1) + area(grid, u, v+1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int max_area = 0;
        for(int u = 0; u < m; u++){
            for(int v = 0; v < n; v++){
                if(grid[u][v]){
                    max_area = max(max_area, area(grid,u,v));
                }
            }
        }

        return max_area;

    }

int main(){
    
 cout << endl;
return 0;
}