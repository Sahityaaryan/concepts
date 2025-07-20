#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())
#define ll long long
#define F first
#define S second
#define ln(s) ((int)(s).length())
#define umci unordered_map<char, int>
#define umii unordered_map<int, int>
#define umsi unordered_map<string, int>
#define sst stringstream

/*
    Leetcode (2342): https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

    learning: I wasn't thinking in that direction, I would have
    used pen and paper i could have broke the pattern

*/

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = sz(nums);
        int ans = -1;
        vi mp(82, -1);

        for(int ele:nums){
            int dig_sum = digit_sum(ele);
            if(mp[dig_sum] != -1){
                ans = max(ans, ele + mp[dig_sum]);
            }
            mp[dig_sum] = max(mp[dig_sum], ele);
        }
        return ans;
    }
private:
    int digit_sum(int num){
        int sum = 0;
        while(num){
            sum += (num%10);
            num/=10;
        }
        return sum;
    }
};


int main(){

    return 0;
}
