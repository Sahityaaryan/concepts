#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool bs(vector<int> &arr , int t){
        int mid,lo = 0, hi = arr.size()-1;

        while(lo <= hi){

            mid = lo + (hi-lo)/2;

            if(arr[mid] == t){
                return true;
            } else if(arr[mid] > t){
                hi = mid-1;
            } else {
                lo = mid + 1;
            }
        }

        return false;
    }

// but it is more log(m) * log(n) but it should be log(m*n)
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {

    //     int mid,hi = matrix.size()-1,lo =0,m = matrix[0].size();
    //     int t = target;

    //     while(lo <= hi){
    //        mid = lo + (hi-lo)/2;

    //        if(matrix[mid][0] == t || matrix[mid][m-1] == t){
    //             return true;
    //        }

    //        if(matrix[mid][0] < t && matrix[mid][m-1] > t){
            
    //         if(bs(matrix[mid],t)){
    //             return true;
    //         }
    //          lo = mid+1;

    //        } else if(matrix[mid][0] > t){
    //         hi = mid-1;
    //        } else {
    //         lo = mid+1;
    //        }
    //     }

    //     return false;
        
    // }

    // ************ here is the solution for the log(m*n) time complexity 

    // Then it is like indexing the entire array virtually: It helps to apply the 1d array binary search in 2d array but more efficient method is belowt

    //  bool searchMatrix(vector<vector<int>>& matrix, int target) {

    //     int mid, lo = 0, n = matrix.size(),m = matrix[0].size(),row, col;
    //     int hi = m*n-1;

    //     while(lo <= hi){
    //         mid = lo + (hi-lo)/2;

    //         row = mid/m; 
    //         col = mid % m;

    //         if(matrix[row][col] == target){
    //             return true;
    //         } else if(matrix[row][col] > target){
    //             hi = mid-1;
    //         } else {
    //             lo = mid + 1;
    //         }
            
    //     }

    //     return false;


    //  }


    //  Searching on the elimination method : (Biunary Search:- Eliminating one option out of the two given option) : T.c => (M+N)

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int mid, lo = 0, m = matrix.size(), n = matrix[0].size();

        int row=0,col=n-1;

        while(row<m && col >= 0){

            if(matrix[row][col]==target) return true;

            if(matrix[row][col] > target) col--;
            else row++;
        }

        return false;
    }
    


};

int main()
{

    //  this is the highly optimized something that I could find
    
    cout << endl;
    return 0;
}