#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * 1ll -> 1 in long long integer type
 *
 */

ll maxGcdScore(vector<int>& nums, int k){
    int size = nums.size();
    vector<int> twoDivisorCount(size,0);

    for(int i = 0; i < size; ++i){
        int val = nums[i];
        while(val%2 == 0){
            twoDivisorCount[i]++;
            val /= 2;
        }
    }

    ll maxGcd = 0ll;

    for(int i = 0; i < size; ++i){
        int currGcd = 0ll;
        int minTwoDivisor = 1e9;
        int minTwoDivisorCount = 0;

        for(int j = i; j < size; ++j){
            currGcd = gcd(currGcd, nums[j]);

            if(minTwoDivisor > twoDivisorCount[j]){
                minTwoDivisor = twoDivisorCount[j];
            }
            if(twoDivisorCount[j] == minTwoDivisor){
                minTwoDivisorCount++;
            }
            int currentLength = j-i+1;
            if(minTwoDivisorCount <= k){
                maxGcd = max(maxGcd, 2ll*currentLength*currGcd);
            } else {
                maxGcd = max(maxGcd, 1ll*currentLength*currGcd);
            }
        }
    }
}








int main(){

    return 0;
}
