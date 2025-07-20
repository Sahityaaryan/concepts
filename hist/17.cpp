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
 *
 * leetcode (2750) :-> https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/description/
 *
 * Pattern identified:-> Gap Multiplication Pattern
 *
 *
    here i just observed whata the question demands and tehn found an optimized way
    to do it. it took me a lot of time because

    1. I didn't understand the question -> like it is saying of building partitions
    such that all the remaining subarray remains good

    2. the way I was thinking of increasing partitions actually it is a
    multiplicative in nature

    3. sometimes while using MOD doesn't give you the perfect answer try changing
    the data type of the answer storing variable like see (int, unsigned int,
     long long).
*/

class Solution {
public:
    int MOD = 1e9+7;

    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = sz(nums);
        int sum = 0, last_occur = 0;
        long long count = 1;

        for(int i = 0; i < n; ++i){
            int num = nums[i];
            if(num==0) continue;
            sum++;
            if(sum > 1){
                count = (1ll*count* (i-last_occur))%MOD;
                sum--;
            }
            last_occur = i;
        }

        if(sum==0) return 0;

        return count;
    }
};

int main(){

    return 0;
}
