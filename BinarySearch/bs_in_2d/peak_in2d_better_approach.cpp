#include<bits/stdc++.h>
using namespace std;

bool checker(vector<vector<int>>& mat, int row, int col) {

        int m = mat.size(), n = mat[0].size();
        int peakElement = mat[row][col];

        int down=-1,up=-1,right=-1,left=-1;

       // edge case

        // is upper exists?
        if(row>0){
            up = mat[row-1][col];
        }

        if(row < m-1){
            down = mat[row+1][col];
        }

        if(col > 0){
            left = mat[row][col-1];
        }

        if(col < n-1){
            right = mat[row][col+1];
        }

        if (peakElement > left && peakElement > right && peakElement > up &&
            peakElement > down) {
            return true;
        }

        return false;
    }



int main()
{
 
    
    cout << endl;
    return 0;
}