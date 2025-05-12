#include<bits/stdc++.h>
using namespace std;


/**
 * 
 * link :-> https://leetcode.com/problems/house-robber-ii/
 * 
 * this question is an amazing question simple crux :-> you have to apply the house-robber in two array which have either 0 th index element or the last element
 * 
 * 
 * Learning :-> how to create an array by taking elements out of other arrays.
 * 
 * vector<int> part1(nums.begin(), nums.begin()+ n-1); //// nums.begin()+ n-1 does point to nums[n-1] but it won't include the nums[n-1] it includeds only upto one before (nums[n-2])
 * 
 * 
 * 
 */
 
int rob(vector<int>& nums) {

    int n = nums.size();

    if(n == 1) return nums[0];
    if(n == 2) return max(nums[0], nums[1]);
    
     int max_profit = INT_MIN;
    vector<int> dp(n-1, -1);


     // case 1:- creating an array from elements 0 to n-2

     vector<int> part1(nums.begin(), nums.begin()+ n-1);
     dp[0] = part1[0];

     max_profit = max(max_profit, dp[0]);
     
     
     for(int i = 1; i < part1.size(); i++){
         int temp_max_profit = part1[i];
         int p = i-2;
         
         while(p >= 0){
             temp_max_profit = max(temp_max_profit, part1[i] + dp[p]);
             p--;
         }

         dp[i] = temp_max_profit;

         max_profit = max(max_profit, dp[i]);
     }


     // case 2 :- creating an array from elements 1 to n-1

     fill(dp.begin(), dp.end(), -1);
     
     vector<int> part2(nums.begin()+1, nums.end());
     dp[0] = part2[0];


     max_profit = max(max_profit, part2[0]);

     for(int i = 1; i < part2.size(); i++){
         int temp_max_profit = part2[i];
         int p = i-2;

         while(p >= 0){
             temp_max_profit = max(temp_max_profit, part2[i] + dp[p]);
             p--;
         }

         dp[i] = temp_max_profit;
         max_profit = max(max_profit, dp[i]);
     }

     return max_profit;


 }

int main(){
    
    cout << (-2 % 4);


 cout << endl;
return 0;
}