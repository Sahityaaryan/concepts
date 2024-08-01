#include<bits/stdc++.h>
using namespace std;

    bool check(vector<string>& board,int v,int h, int n){

        int i = v-1, j = 0;

        // top
        while(i + 1){

            if(board[i][h] == 'Q'){
                return false;
            }
            i--;
        }

        // left check: no need of right check because we are placing the queen left to right

        j = h-1;

        while(j+1){
            if( board[v][j] == 'Q'){
                return false;
            }
            j--;
        }

        // left kona kani

        i = v-1; j = h-1;

        while((i + 1) && (j+1)){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }


        // right kona kani

        i = v-1; j = h+1;

        while( (i+1) && (j < n)){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j++;
        }

        return true;

    }

    void sol(int v,int h, vector<string>& board, vector<vector<string>>& ans, int& n){

        if(v == n){
                ans.emplace_back(board);
                return;
            } 

          int j = 0;

            while(j < n){
                
                if(check(board,v,j,n)){
                    board[v][j] = 'Q';
                    sol(v+1,j,board,ans,n);
                    board[v][j] = '.';
                }
                j++;
            }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        string temp = "";
        int i = 0;
        while(i < n){
            temp += '.';
            i++;
        }

        vector<string> board(n,temp);
        
        sol(0,0,board, ans,n);            

        return ans;
    }
int main()
{
    int n = 4;
    vector<vector<string>> ans = solveNQueens(n);

    for(auto it:ans){
        for(string i: it){
            cout << i << "    ";
        }
        cout << endl;
    }




    cout << endl;
    return 0;
}