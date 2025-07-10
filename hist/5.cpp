#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode 410
 *
 * challenge :-> https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/description/ (1723)
 * challenge :-> https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/ (698)
 *
 */

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int final = accumulate(begin(nums), end(nums), 0);
        int st = *max_element(begin(nums), end(nums));

        while(st <= final){
            int mid = st + (final-st)/2;
            if(isValid(nums, mid, k)) final = mid-1;
            else st = mid+1;
        }
        return st;
    }

    bool isValid(vector<int>& nums, int mid, int k){
        int count = 1, temp = 0;

        for(int num:nums){
            if(temp + num > mid){
                temp = num;
                count++;
            } else temp += num;
        }

        return count <= k;
    }
};

int main(){

    return 0;
}
