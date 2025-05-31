#include<bits/stdc++.h>
using namespace std;

/*
    question:-> https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
     problem :-> Ik have almost reached the question but my way of calculating things were not good

     I have to understand that how the subsets/subsequences are calculated:->
     1. it's simple take , not_take concept for each elemet like for arr=[1,2,3] (if you want all susbsequence containg 1 then it will be 4 because for the rest two it's whether you will take them or not so 2^2 posibilities are there)
     2. if you want to calculate sum of subsequences or min max among them, then the order of there elements doesn't matter you can sort the array as well

*/

class Solution {
public:
    int MOD = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {

        int n = nums.size(), sum = 0;
        int r = n-1, l = 0;

        vector<int> power;
        power.push_back(1);

        for(int i = 1; i < n; i++){
            power.push_back((power.back() << 1) % MOD);
        }

        sort(nums.begin(), nums.end());

        while(l <= r){
            if(nums[l] +  nums[r] <= target){
                sum = ((sum % MOD) + power[r-l]) % MOD;
                l++;
            } else r--;
        }
        return sum;
    }
};



int main(){

    return 0;
}
