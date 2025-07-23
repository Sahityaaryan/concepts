#include<bits/stdc++.h>
using namespace std;


#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())
#define ll long long
#define F first
#define S second
#define ln(s) ((int)(s).length())
#define umci unordered_map<char, int>
#define umii unordered_map<int, int>
#define umsi unordered_map<string, int>
#define sst stringstream

/*
 * bottom-up approach for the (mcm)
 * -> important thing for the bottom up appraoch you need two things to understand (1. base case, 2. what a state represents, 3. how the previous state
 * is helpfull in the further calculations)
 *
 * # Rules
 * 1. remember the base case (i==j) dp[i][j] = 0;
 * 2. and everything even the logic remains the same as it was for the (top-down approach)
 *
 * but what does (dp[i][j]) signifies
 * dp[i][j] => what is the least number of calculations you have to do while multiplying every matriix from ith position to n-1th position (indexing is according to the given array)
 *
 */



     int matrixMultiplication(vector<int> &arr) {
         const int n = sz(arr);

         ll dp[n][n];

         for(int i = 0; i < n; ++i){
             dp[i][i] = 0ll;
         }

         for(int i = n-1; i >= 1; --i){
             for(int j = i+1; j < n;++j){
                 ll mini = LONG_LONG_MAX;
                 for(int k = i; k < j; ++k){
                     ll calc = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];

                     if(calc < mini) mini = calc;
                 }
                 dp[i][j] = mini;
             }
         }

         return dp[1][n-1];
     }


int main(){

    return 0;
}
