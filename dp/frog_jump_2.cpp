
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

/*
    Learning :- if you want to some solve a question then figure out the pattern from a small testcase then increasing it bit by bit to big testcase while analyzing the pattern
*/
    int maxJump(vector<int>& stones) {
        int diff = INT_MIN;
        int n = stones.size();

        if(n == 2) return stones[1] - stones[0];

        for(int i = 0; i < n-2; i++){
            diff = max(diff, stones[i+2] - stones[i]);
        }

        return diff;
    }
};


int main(){

    return 0;
}
