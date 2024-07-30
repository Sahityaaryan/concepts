#include<bits/stdc++.h>
using namespace std;

// Backtracking: 


bool sol(vector<vector<char>>& board, string& word, int vertical,
             int horizontal, string temp, int index) {


        if (index == word.length()) {
            return true;
        }

        if (vertical == board.size() || vertical < 0 || horizontal < 0 ||
            horizontal == board[0].size() || word[index] != board[vertical][horizontal] or board[vertical][horizontal] == '!') {
            return false;
        }


        char c = board[vertical][horizontal];

        board[vertical][horizontal] = '!';

        bool right = sol(board, word, vertical, horizontal+1, temp + board[vertical][horizontal], index + 1);

        bool left = sol(board, word, vertical , horizontal - 1, temp + board[vertical][horizontal], index + 1);

        bool down  = sol(board, word, vertical + 1, horizontal, temp + board[vertical][horizontal],  index + 1);

        bool up  = sol(board, word, vertical - 1, horizontal, temp + board[vertical][horizontal], index + 1);
            
        board[vertical][horizontal] = c;

        return right || left || down || up;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        // founder

        int i = 0, j = 0, height = board.size(), width = board[0].size();

        while(i < height){

            j = 0;

            while(j < width){

                if(word[0] == board[i][j] && sol(board, word, i, j, "", 0)){
                    return true;
                }

                j++;
            }
            i++;
        }

        return false;

    }

int main()
{

    
    vector<vector<string>> ans = partition("aab");

    cout << "printing:\n"; 

    for(auto it:ans){
        for(auto str:it){
            cout << str << " ";
        }
        cout << endl;
    }


    
    cout << endl;
    return 0;
}