#include<bits/stdc++.h>
using namespace std;

/*
 *
 * Leetcode (300) -> https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * This is the perfect example where I got the taste tha dp not always give answer in O(n) sometimes optimized solution alos take O(N^2)
 * so the important things is to solve the question and later think of it's optimized version
 */

 /**
  * Optimized :-> but there is a problem it can only give you correct length of the longest increasing subsequence but it can't give
  * you the correct longest increasing subsequence  because it may change the order of digits
  *
  * class Solution {
  public:
      int lengthOfLIS(vector<int>& nums) {
          vector<int> queue;
          for(const auto &n: nums) {
              auto it = lower_bound(queue.begin(), queue.end(), n);
              if(it == queue.end()) {
                  queue.push_back(n);
              } else {
                  *it = n;
              }
          }
          return queue.size();
      }
  };
  *
  */

 /*
  * Mine solution
  */
  class Solution {
  public:
      int lengthOfLIS(vector<int>& nums) {
          int n = nums.size();
// here in this dp actually I am storing how many elements are there on the right side of the ith element strictly greater than it.
          int count = 0;

          vector<int>dp(n,1);

          for(int i = n-1; i >= 0; --i){
              int subs = 0;
              for(int j = i+1; j < n; ++j){
                  if(nums[i] < nums[j] && subs < dp[j]){
                      subs = max(subs, dp[j]);
                  }
              }
              dp[i] += subs;
              count = max(dp[i],count);
          }

          return count;
      }
  };





int main(){

    return 0;
}
