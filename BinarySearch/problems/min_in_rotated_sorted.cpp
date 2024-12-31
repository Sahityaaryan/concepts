#include <bits/stdc++.h>
using namespace std;

// How to find the minimum in rotated sorted Array=>

  int findMin(vector<int>& arr) {
      int n = arr.size();

      // check the size of the array

      if(n == 0) return -1;

      // if it is not rotated sorted or have only one element
      if(arr[0] < arr[n-1] || n==1){
          return arr[0];
      }

      int l = 0;
      int r = n-1;

      while(l <= r){
          int m = l + (r-l)/2;

          if(arr[m] >= arr[0]) l = m+1;
          else r = m-1;
      }

      return arr[l];
  }

int main(){

    return 0;
}
