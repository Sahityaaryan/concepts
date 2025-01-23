#include<bits/stdc++.h>
using namespace std;
 

// 130. Surrounded Regions

/*
    This question is again based on the same pattern + one different pattern

    1. backtracking and iterating through all possible directions
    2. If we want to include the end or leaf nodes in the answer then why not to start with them
*/

    void sol(vector<vector<char>>& board, int u, int v){

        if(u >= board.size() || u < 0 || v >= board[0].size() || v < 0) return;

        if(board[u][v] == 'B') return;
        if(board[u][v] == 'X') return;

        board[u][v] = 'B';
        
         sol(board, u, v+1);
         sol(board, u, v-1);
         sol(board, u-1, v);
         sol(board, u+1, v);
    }

    void solve(vector<vector<char>>& board) {

        vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size()));
        int m = board.size();
        int n = board[0].size();
        int upos[2] = {0, m-1};
        int vpos[2] = {0, n-1};
        

        // traversing through the sides

        for(int u = 0; u < 2; u++){
            for(int v = 0; v < board[0].size(); v++){
                if(board[upos[u]][v] == 'O' && !isVisited[upos[u]][v]){
                    sol(board, upos[u], v);
                }
            }
        }

            for(int v = 0; v < 2; v++){
                for(int u = 0; u < board.size(); u++){
                    if(board[u][vpos[v]] == 'O' && !isVisited[u][vpos[v]]){
                        sol(board, u, vpos[v]);
                    }
            }
        }

// modifying the array to recover the required answer

        for(int u = 0; u < board.size(); u++){
            for(int v = 0; v < board[0].size(); v++){
                if(board[u][v] == 'O'){
                    board[u][v] = 'X';
                } else if(board[u][v] == 'B'){
                    board[u][v] = 'O';
                }
            }
        }
    }


int main(){
    
 cout << endl;
return 0;
}