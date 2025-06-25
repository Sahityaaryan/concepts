#include<bits/stdc++.h>
using namespace std;

/*
 *
 * question : 494 (target sum) :_> https://leetcode.com/problems/target-sum/
 */


class Solution {

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int totalSum = 0;
        for(auto& num : nums) {
            totalSum += num;
        }
        if(target + totalSum < 0 || (target + totalSum) % 2 != 0) return 0;
        int s1 = (target + totalSum) / 2;
        vector<int> prev(s1 + 1, 0);
        vector<int> curr(s1 + 1, 0);
        prev[0] = 1;
        curr[0] = 1;

        if(nums[0] <= s1) prev[nums[0]] = 1;
        if(nums[0] == 0) prev[0] = 2;

        for(int index = 1; index < n; index++) {
            for(int target = 0; target <= s1; target++) {
                int include = 0;
                if(nums[index] <= target) include = prev[target - nums[index]];
                int exclude = prev[target];
                curr[target] = include + exclude;
            }
            prev = curr;
        }
        return prev[s1];
    }
};


int main(){

    return 0;
}
