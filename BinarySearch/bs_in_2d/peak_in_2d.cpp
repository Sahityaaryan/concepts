#include<bits/stdc++.h>
using namespace std;

//  checker : checks that whether it is actually a peak or not? means
    //  surrounding element are lower than it or not
    bool checker(vector<vector<int>>& mat, int row, int col) {

        int m = mat.size(), n = mat[0].size();
        int peakElement = mat[row][col];

        //  edge cases:

        // nested constraints for the upper elements

        if (row == 0) {

            int down = mat[row + 1][col];

            if (peakElement < down) {
                return false;
            }

            if (col == 0 ) { // edge case: IF column is not zero then also we got the false.
            if(peakElement > mat[row][col + 1]){
                return true;
            } else {
                return false;
            }
        }

            if (col == n - 1) {
                if(peakElement > mat[row][col - 1]){
                    return true;
                } else {
                    return false;
                }
            }

            if (peakElement > mat[row][col - 1] && peakElement > mat[row][col + 1]) {
                return true;
            } else {
                return false;
            }
        }

        if (row == m - 1) {
            int up = mat[row - 1][col];

            if (peakElement < up) {
                return false;
            }

            if (col == 0 ) {

                if(peakElement > mat[row][col + 1]){
                    return true;
                } else {
                    return false;
                }
            }

            if (col == n - 1) {
                if(peakElement > mat[row][col - 1]){
                    return true;
                } else {
                    return false;
                }
            }

            if (peakElement > mat[row][col - 1] &&
                peakElement > mat[row][col + 1]) {
                return true;
            } else
                return false;
        }

        // I have to handle separately the edge cases of the column as well

         if (col == 0 ) {

            if(peakElement > mat[row + 1][col] || peakElement > mat[row-1][col]){
                return false;
            }

                if(peakElement > mat[row][col + 1]){
                    return true;
                } else {
                    return false;
                }
            }

            if (col == n - 1) {

            if(peakElement > mat[row + 1][col] || peakElement > mat[row-1][col]){
                return false;
            }

                if(peakElement > mat[row][col - 1]){
                    return true;
                } else {
                    return false;
                }
            }



        int left = mat[row][col - 1], right = mat[row][col + 1],
            up = mat[row - 1][col], down = mat[row + 1][col];

        if (peakElement > left && peakElement > right && peakElement > up &&
            peakElement > down) {
            return true;
        }

        return false;
    }



     int colOfPeakElement(vector<int> arr) { // getting the maximum element of the whole array due to case no. 52
        int i = 0,n = arr.size(), maxi = INT_MIN,col=0;

        while(i < n){

            if(maxi < arr[i]){
                maxi = arr[i];
                col = i;
            }
            i++;
        }
        return col;
     }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // the answer is whosoever fullfills the checker condtion will be our
        // answer

        int i = 0, currentPeakCol;
        int m = mat.size();

        while (i < mat.size()) {

            currentPeakCol = colOfPeakElement(mat[i]);

            if(m==1){ // this is the case to handle an edge case when we have only single row then the largest element of the row is the answer
                return {i,currentPeakCol};
            }

            if (checker(mat, i, currentPeakCol) && m>1) { 
                return {i, currentPeakCol};
            }
            i++;
        }
        return {-1, -1};
    }

int main()
{

    // vector<vector<int>> v = {{36,15,44,21,50},{50,4,15,3,21},{26,18,5,14,37},{46,21,14,42,32},{26,42,30,10,17}};
    //  vector<vector<int>> v = {{8,51,36,25,16,59,12,85,28,83,82,77,3},{7,43,32,17,73,27,9,98,71,27,76,28,30},{43,100,19,77,1,36,19,17,70,33,23,15,85},{4,17,2,46,31,76,42,3,23,34,7,17,95},{54,68,15,96,9,61,58,100,47,66,76,14,58},{65,29,79,6,94,85,67,39,59,83,4,8,62},{52,55,88,14,63,92,57,10,11,42,78,19,9},{17,36,80,82,75,71,92,42,49,77,68,38,59},{65,78,56,13,90,15,84,99,71,93,28,56,58},{30,53,44,59,52,54,94,13,41,55,41,86,33},{48,20,88,61,9,12,11,12,56,13,96,95,48},{17,72,8,76,72,43,86,16,53,46,86,97,55},{93,7,37,77,40,46,14,74,65,28,20,85,62},{29,14,45,72,48,15,98,36,74,29,55,72,99},{80,79,87,83,72,4,78,85,89,35,4,24,35},{90,98,40,44,45,1,24,19,73,85,52,9,19},{95,82,4,12,96,68,28,49,54,59,44,21,48},{40,93,42,100,73,77,11,7,20,21,97,80,7},{87,11,35,57,85,55,63,78,57,54,35,28,97},{66,15,45,56,15,37,87,76,63,68,86,40,6},{29,51,77,8,1,27,39,28,99,18,98,33,38},{42,16,1,64,96,56,23,17,49,69,91,30,65}};

     
   vector<vector<int>> v = {{10,50,40,30,20},{1,500,2,3,4}};

    vector<int> ans = findPeakGrid(v);

    // printing the array

    for(int i:ans){
        cout << i << endl;
    }
    
    cout << endl;
    return 0;
}



