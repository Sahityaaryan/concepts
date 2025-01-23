#include<bits/stdc++.h>
using namespace std;
 

//  797. All Paths From Source to Target

/*
    This is a pattern which teaches us the how to get the path
*/

     void dfs(vector<vector<int>>& adj, int v, vector<bool>& isV, vector<int>& temp, vector<vector<int>>& paths, int n){
        if(v == n){
            paths.push_back(temp);
            return;
        }

        isV[v] = true;

        for(int x:adj[v]){
            if(!isV[x]){
                temp.push_back(x);
                dfs(adj, x, isV, temp, paths, n);
                temp.pop_back();
            }
        }

        isV[v] = false;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
            vector<vector<int>> paths;
            vector<int> temp;
            vector<bool> isV(adj.size());
            temp.push_back(0);
            dfs(adj, 0, isV, temp, paths, adj.size()-1);
            
            return paths;
    }


int main(){
    
 cout << endl;
return 0;
}