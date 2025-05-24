#include<bits/stdc++.h>
using namespace std;


/*

    link:-> https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
    my problem -> I wasn't able to undersand how to do this question using the bottom-up approach
    solution -> Always in the bottom-up approach remember that you have to built a vector such that each value of it at a particular place, gives the answer if that particular value  would be given as the final destination

    like in this question we have calculated in our dp for a particular index let's check from 1 to sum how many subsets we can match.

    if you want a clear understanding make the dp array according to the solution for the input (arr =[1,2,3] , sum=6)

    const dp = [
      [true,  false, false, false, false, false, false],
      [true,  true,  false, false, false, false, false],
      [true,  true,  true,  true,  false, false, false],
      [true,  true,  true,  true,  true,  true,  true ]
    ];

*/

bool isSubsetSum(vector<int>& arr, int sum) {
    // code here
     int n = arr.size();
    bool t[n+1][sum+1];

    //initialization
    for (int i=0; i<n+1; i++) {
        for (int j = 0; j< sum+1; j++) {
            if (i == 0) {
                t[i][j] = false;
            }

            if (j==0) {
                t[i][j] = true;
            }
        }
    }

    for(int i = 1; i< n+1; i++) {
        for (int j = 1; j < sum+1; j++) {
            if (arr[i-1] <= j) {
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main(){

    return 0;
}
