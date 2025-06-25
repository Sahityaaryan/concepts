#include<bits/stdc++.h>
using namespace std;

/*
    link:-> https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

*/


// tabulation

int minCost(vector<int>& height) {
    // Code here
    int n = height.size();
    vector<int> dp(n,0);

    dp[0] = 0;

    if(n > 1) dp[1] = abs(height[0] - height[1]);


    for(int i = 2; i < n; i++){
        dp[i] = min(abs(height[i] - height[i-1]) + dp[i-1], abs(height[i] - height[i-2]) + dp[i-2]);
    }

    return dp[n-1];
}



// memoization

int sol(vector<int>& h,int n, vector<int>& dp){

    if(dp[n] != -1) return dp[n];

    return dp[n] = min( abs(h[n]- h[n-1]) + sol(h,n-1, dp), abs(h[n] - h[n-2]) + sol(h,n-2, dp));
}

  int minCost(vector<int>& height) {
      // Code here
      int n = height.size();
      vector<int> dp(n,-1);

      dp[0] = 0;
      if(n>1) dp[1] = abs(height[0] - height[1]);

      sol(height, n-1, dp);

      return dp[n-1];
  }



// space optimization

int minCost(vector<int>& height) {
    // Code here
    int n = height.size();
    vector<int> dp(n,0);

    int prev, prev2;

    prev2 =  0;

    if(n > 1) prev = abs(height[0] - height[1]);


    for(int i = 2; i < n; i++){
        dp[i] = min(abs(height[i] - height[i-1]) + prev, abs(height[i] - height[i-2]) + prev2);
        prev2 = prev;
        prev = dp[i];
    }

    return dp[n-1];
}


int main(){

 cout << endl;
return 0;
}
