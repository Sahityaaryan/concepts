#include<bits/stdc++.h>
using namespace std;

int mod=1000000007;


/**
 * all the below methods are just for informational purpose to let you know how to write the code of the recursion
 *** but this can be solved only by recursion
 */

bool PrintS(int ind, vector<int> &ds, int s, int sum, int arr[], int n){
    
    if(ind == n){
        return s==sum;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    if(PrintS(ind+1, ds,s ,sum , arr,n)){
        return true;
    }

    s -= arr[ind];
    ds.pop_back();

    if(PrintS(ind+1, ds,s ,sum , arr,n)){
        return true;
    }

    return false;
}

// when solving the count the number of subsequences satisfying a particular situation

int PrintS(int ind, int s,int sum, int arr[], int n){

    if(ind == n){

        if(s == sum) return 1;

        else return 0;
    }

    s += arr[ind];

    int l = PrintS(ind+1, s, sum, arr, n);

    s -= arr[ind];

    int r = PrintS(ind+1, s, sum, arr, n);

    return  l+r;

}



/**
 * Here we are implementing the dp (memoization) which means that we are storing the result on a particular condition like we 
 * know that if till index = 2 if the target is 5 then after further recursion call it will become 23 so why not to store the answer? 
 */


int sol(int ind,int n, int target,int sum, int arr[], vector<vector<int>>& dp) 
{
    if(ind==n){
         if(target == sum){ // answer sirf take wale se aayega
            return 1;
        } else if(target == sum - arr[ind]){ // answer sirf not take wale se aayega
            return 1;
        }

        return 0;
    }

    if(dp[ind][target] != -1){ // if we have the answer in the memory then we must return it if not then we will calculate further
        return dp[ind][target];
    }


    int notTake = sol(ind+1, n, target, sum, arr, dp);

    int take  = 0;

    if(arr[ind] + target <= sum ){
        take = sol(ind+1,n, target+arr[ind], sum,arr,dp);
    }

    return dp[ind][target] = ((take % mod) + (notTake % mod)) % mod;
}
    
int perfectSum(int num[], int n, int k)
{
        vector<vector<int>> dp(n, vector<int>(k + 1, -1)); 
        return sol(0,n, 0, k ,num, dp);
        
}

int main()
{

    int num[] = {5,2,3,10,6,8};
    int n = sizeof(num)/sizeof(num[0]);

    int k =10;

    cout << "\nans: " << perfectSum(num, n, k) << endl;

    cout << endl;
    return 0;
}