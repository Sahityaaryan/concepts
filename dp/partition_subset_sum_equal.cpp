#include<bits/stdc++.h>
using namespace std;

/*

question:-> https://leetcode.com/problems/partition-equal-subset-sum/description/

learning -> It took me very long to solve this problem because, I was stuck at my understanding of dp that if you have to solve a recursion kind problem
then your answer must be the recursive  steps of solving the same problem but with fewer portions of the given array, but it's actually the tricky problem
where i just have to see that if the we want equal subset sum, then the total sum must be divisible by 2 and (sum/2) is your new targetSum to find

*/

bool canPartition(vector<int>& nums) {
       int totalSum = 0;
       for (int num : nums) totalSum += num;

       if (totalSum % 2 != 0) return false;

       int targetSum = totalSum / 2;
       vector<bool> dp(targetSum + 1, false);
       dp[0] = true;
       for (int num : nums) {
           for (int currSum = targetSum; currSum >= num; --currSum) {
               dp[currSum] = dp[currSum] || dp[currSum - num];
               if (dp[targetSum]) return true;
           }
       }
       return false;
   }

int main(){

    return 0;
}
