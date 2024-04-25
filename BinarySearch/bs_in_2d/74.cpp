#include<bits/stdc++.h>
using namespace std;

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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int mid,hi = matrix.size()-1,lo =0,m = matrix[0].size();
        int t = target;

        while(lo <= hi){
           mid = lo + (hi-lo)/2;

           if(matrix[mid][0] == t || matrix[mid][m-1] == t){
                return true;
           }

           if(matrix[mid][0] < t && matrix[mid][m-1] > t){
            
            if(bs(matrix[mid],t)){
                return true;
            }
             lo = mid+1;

           } else if(matrix[mid][0] > t){
            hi = mid-1;
           } else {
            lo = mid+1;
           }
        }

        return false;
        
    }

int main()
{
 
    
    cout << endl;
    return 0;
}