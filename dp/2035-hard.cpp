#include <algorithm>
#include<bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
public:
int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int N = n/2, sum = 0;

    sum = accumulate(nums.begin(), nums.end(), 0);


    // 1. formation of the left and right;
     vector<vector<int>> left(N + 1), right(N+1);

     for(int mask = 0; mask < (1<<N);++mask){
        int size = 0, l_sum = 0, r_sum = 0;

        for(int j = 0; j < N; j++){
            if( mask & (1<<j)){
                size++;
                l_sum += nums[j];
                r_sum += nums[N + j];
            }
        }

        left[size].push_back(l_sum);
        right[size].push_back(r_sum);
     }

     for(int i = 0; i < N; i++){
         sort(right[i].begin(), right[i].end());
     }

    int res = min(abs(sum - 2*left[N][0]), abs(sum - 2*right[N][0]));

    for(int i = 1; i < N;i++){
        for(int a: left[i]){
            int b = (sum - 2*(a))/2, rsg = N-i;

            auto& right_arr = right[rsg];

            auto itr = lower_bound(right_arr.begin(), right_arr.end(), b);

            if(itr != right_arr.end()) res = min(res, abs(sum - 2*(a + *itr)));
            if(itr != right_arr.begin()) res = min(res, abs(sum- 2*(a + *(itr-1)))); // case when the all the values of the right_arr are bigger than the b
        }
    }

    return res;
}
};

// T.C : O(2^N/2 + 2^N/2 * log(2 ^ N/2)) --> O(2^N/2 * log(2 ^ N/2));
// S.C : O(2^N/2)

int main(){

    return 0;
}
