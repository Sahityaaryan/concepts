#include<bits/stdc++.h>
using namespace std;

    bool sol(vector<vector<char>>& board, string& word, int vertical,
             int horizontal, string temp, int v_index, int h_index) {


        cout << "temp: " << temp << " vertical: " << vertical
             << " horizontal: " << horizontal << '\n';

        if (vertical == board.size() || vertical < 0 || horizontal < 0 ||
            horizontal == board[0].size()) {
            return false;
        }

        if (temp.length() > 0 &&
            temp[temp.length() - 1] != word[temp.length() - 1]) {
            return false;
        }

        if (temp.length() == word.length()) {
            return temp == word;
        }

        bool searching  =   sol(board, word, vertical, horizontal - 1, temp + board[vertical][horizontal], v_index, h_index) ||
                            sol(board, word, vertical, horizontal + 1, temp + board[vertical][horizontal], v_index, h_index) ||
                            sol(board, word, vertical + 1, horizontal, temp + board[vertical][horizontal], v_index, h_index);

            if(searching){
                return true;
            }

        int i = v_index;
        int j = h_index == board[0].size() ? 0:h_index;

        bool isFound = false;

        while (i < board.size()) {

            bool searching = false;

            while (j < board[0].size()) {

                if (board[i][j] == word[0]) {
                        searching =
                            sol(board, word, i, j - 1, temp + board[i][j], v_index, j+1) ||
                            sol(board, word, i, j + 1, temp + board[i][j], v_index, j+1) ||
                            sol(board, word, i + 1, j, temp + board[i][j], v_index, j+1);
                }

                j++;
            }

            j = 0;

            isFound = isFound || searching;
            i++;
        }

        return isFound;
    }

    bool exist(vector<vector<char>>& board, string word) {
        return sol(board, word, 0, 0, "", 0, 0);
    }

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
