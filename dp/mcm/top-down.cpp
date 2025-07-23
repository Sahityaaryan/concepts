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
    I got one doubt initally here it's okay to do sol(k+1,j) but why are we going the
    sol(i,k) -> because we have just calculated the numhber of caculation required in the
    multiplication of a (i-1,k) * (k,j) -> matrix but these (i-1,k) and (k,j) must also
    be the result of some multiplication , here no matter how you do multiply the dimension
    of the matrix remains same at the end you justa hve to choose a way of multiplication
    of matrices that result in minimum calculations so you are thinking of the min
    caculations to form the (i-1,k) and (k,j) matrices

*/

class Solution {
  public:

    int matrixMultiplication(vector<int> &arr) {
        int n = sz(arr);
        vvi dp(n, vi(n,-1)); // minimum calculations to form the matrix of dimension (i-1,j)

        return sol(arr,1,n-1,dp);
    }

    private:

        ll sol(vi& arr,int i, int j, vvi& dp){
            if(i==j) return 0; // now we don't have a matrix at all
            if(dp[i][j] != -1) return dp[i][j];
            ll least_calculations = 1e12;

            for(int k = i; k < j; ++k){
                ll calc = (1ll*arr[i-1]*arr[k]*arr[j]) + sol(arr,i,k,dp) + sol(arr,k+1,j,dp);
                least_calculations = min(least_calculations,calc);
            }

            return dp[i][j] = least_calculations;
        }

};

int main(){

    return 0;
}
