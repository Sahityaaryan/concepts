#include<bits/stdc++.h>
using namespace std;

  bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int col = 0, n = matrix.size(), m = matrix[0].size();
        int row = n-1;

        while(row >= 0 && col < m){

            if(matrix[row][col] == target){
                return true;
            } else if(matrix[row][col] < target){
                col++;
            } else {
                row--;
            }
        }

        return false;
    }

int main()
{

    //  this is the highly optimized something that I could find
    
    cout << endl;
    return 0;
}