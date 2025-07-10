#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ll long long
#define F first
#define S second
#define ln(s) (int)s.length()
#define umci unordered_map<char, int>
#define umii unordered_map<int, int>
#define umsi unordered_map<string, int>


/**
 *
 * /// -----> brahmastra for counting the subarray sum or subarray count
 *
 *
 * -- similar question (1248) -- must solve (1358)
 *
 * Learning :-> sometimes
 * find the the number of those subarray in the entire array which equals to a particular sum = no. of subarray which which is contributing extra
 * number to the sum
 *
 * [1,0,1,0,1] -> total sum = 3, goal = 2
 * no. of previous subarrays which is inlcluding extra par in the array (extra part = 3-2) = 2 {[1], [1,0]}
 *
 */


class Solution {
public:

 int numSubarraysWithSum(vector<int>& nums, int goal) {

    int total_subarrays = 0, curr_sum = 0;

    int total_sum = accumulate(all(nums),0);

    vi dp(total_sum+1,0);
    // here the dp is storing the number of subarrays sum equal to the curr_sum
    dp[0] = 1;

    for(int num:nums){
        curr_sum += num;
        if(curr_sum - goal >= 0) total_subarrays += dp[curr_sum-goal];
        dp[curr_sum]++;
    }


    return total_subarrays;
    }

};

int main(){

    return 0;
}
