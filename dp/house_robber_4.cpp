#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPossible(vector<int>& nums, int cap, int k){
        int houses = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= cap) houses++;
            if(houses >= k) return true;
        }

        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        if(n==1) return nums[0];

        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        while(l <= r){
            int mid = l + (r-l)/2;

            if(isPossible(nums, mid, k)) r = mid-1;
            else l = mid + 1;
        }

        return l;
    }
};

int main(){


    return 0;
}
