#include<bits/stdc++.h>
using namespace std;


    bool check(vector<vector<char>>& board, int row, int col, char target){

        int strtx = (row/3)*3;
        int strty = (col/3)*3;
        int endx = strtx + 3, endy = strty + 3;

        // Checking within the 3 * 3 box

        while(strtx < endx){

            int j = strty;

            while(j < endy){
               
               if(board[strtx][j] == target){
                return false;
               }

                j++;
            }
            strtx++;
        }


        // checking in entire column
        
        int j = 0;

        while(j < 9){
            if(j != col && board[row][j] == target){
                return false;
            }
            j++;
        }

        // checking in entire row

        int i = 0;

        while(i < 9){
            if(i != row && board[i][col] == target){
                return false;
            }
            i++;
        }
    
        return true;
    }

    void sol(vector<vector<char>>& board, int row, int col, vector<vector<char>>& ans){

        
        if(board[row][col] == '.'){

            int j = 1;

            while(j < 10){
                if(check(board,row,col,char('0'+j))){
                    board[row][col] = char('0'+j);
                    sol(board,row,col+1, ans);
                }
                j++;
            }
        } 
    }

    bool sol(vector<vector<char>>& board){

        int i = 0;

        while(i < 9){
            int j = 0;

            while(j < 9){

                if(board[i][j] == '.'){
                    int c = 1;

                    while(c < 10){

                        if( check(board,i,j,(char)(c + '0'))){
                            board[i][j] = (char)(c + '0');

                            if(sol(board)){
                                return true;
                            } else {
                            board[i][j] = '.';
                        }

                        } 

                        c++; 
                    }

                    return false;
                }
                j++;
            }
            i++;
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        // constraints + == backtracking
        bool flag = sol(board);
    }

int main()
{
    cout << endl;
    return 0;
}