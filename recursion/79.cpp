#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sol(vector<vector<char>>& board, string& word, int vertical,
             int horizontal, int index) {


        if (index == word.length()) {
            return true;
        }

        if (vertical == board.size() || vertical < 0 || horizontal < 0 ||
            horizontal == board[0].size() || word[index] != board[vertical][horizontal] or board[vertical][horizontal] == '!') {
            return false;
        }


        char c = board[vertical][horizontal];

        board[vertical][horizontal] = '!';

        bool right = sol(board, word, vertical, horizontal+1, index + 1);

        bool left = sol(board, word, vertical , horizontal - 1,index + 1);

        bool down  = sol(board, word, vertical + 1, horizontal, index + 1);

        bool up  = sol(board, word, vertical - 1, horizontal, index + 1);
            
        board[vertical][horizontal] = c;

        return right || left || down || up;
    }
                             
    bool exist(vector<vector<char>>& board, string word) {
        
        // founder

        int i = 0, j = 0, height = board.size(), width = board[0].size();


        // Here by this wherever we found any matching char we start our recursion from that very point

        while(i < height){

            j = 0;

            while(j < width){

                if(word[0] == board[i][j] && sol(board, word, i, j, 0)){
                    return true;
                }

                j++;
            }
            i++;
        }

        return false;

    }
};

int main()
{
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "SEE";

    if(exist(board, word)){
        cout<< "found ";
    } else {
        cout << "Not found";
    }
    cout << endl;
    return 0;
}

