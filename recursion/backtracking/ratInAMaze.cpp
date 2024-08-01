#include<bits/stdc++.h>
using namespace std;

    void sol(int v,int h, vector<string>& ans, vector<vector<int>>& mat, string path){
        
        int n = mat.size();
        
        if(v < 0 || h < 0 || v == n || h == n || mat[v][h] == 0){
            return;
        }
        
        if(v == n-1 && h == n-1){
            ans.emplace_back(path);
            return;
        }
        
        
        mat[v][h] = 0;
        
        //  up
        
        sol(v-1, h, ans, mat, path + 'U');
        
        // down
        
        sol(v+1, h, ans, mat, path + 'D');
        
        // left
        
        sol(v, h-1, ans, mat, path + 'L');
        
        // right
        
        sol(v, h+1, ans, mat, path + 'R');
        
        mat[v][h] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        
        vector<string> ans;
        
        sol(0,0, ans, mat, "");
        
        return ans;
    }

int main()
{
    cout << endl;
    return 0;
}