#include<bits/stdc++.h>
using namespace std;

/*
    question:-> https://www.geeksforgeeks.org/problems/geeks-training/1
    Learning: - Dsa is all about thinking of founding a pattern in the question, there are no tough questions at all it's just a small puzzle which you have to solve

    about the solution :-> it's just a bottom up approach at each of the ith position in the array we are calculating the maximum number of points the geek can earn at that ith day

    // but wait :-> how I am making sure that geek is not doing the same thing on the consecutive days
    // as we can see the curr becomes the prev so the first index of the prev is made from the first index of the arr and while are we calculating the max we are not taking the first index of the prev.
    // so we can see that which index of the arr we used becomes the same index in the prev and we are calculating the next maximum without using the same index of the prev
    // and thus we are making sure that we are not using the same index of the arr, next day to calculate the maximum.
*/


int maximumPoints(vector<vector<int>>& arr) {

   vector<int> prev(3,0);
  vector<int> curr(3,0);

   prev[0] = arr[0][0];
   prev[1] = arr[0][1];
   prev[2] = arr[0][2];

   for(int i = 1; i < arr.size(); i++){
       curr[0] = arr[i][0] + max(prev[1], prev[2]);
       curr[1] = arr[i][1] + max(prev[0], prev[2]);
       curr[2] = arr[i][2] + max(prev[0], prev[1]);
       prev = curr;
   }
   return max(prev[0], max(prev[1], prev[2]));
}



int main(){

    return 0;
}
