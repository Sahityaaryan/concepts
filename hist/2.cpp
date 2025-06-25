#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

/*
    leetcode (915) -> https://leetcode.com/problems/partition-array-into-disjoint-intervals/

    learning:-> this questions was all about the recognizing the change in the
    pattern, here pattern in the that chunk identification technique
    there are only two possiblities from index 0 to i

    1. either all the elements from 0 to i will be exactly at same position
     as like their sorted version, so if this pattern breaks then we get our
     partition

    2. either they are not are not at the same positions so, if we found the
    entire chunk of such element which just needs to be sorted to become
    equal to there sorted version, so if this pattern breaks then we get our
    partition

    3. we didn't find any partition break why? -> because the given nums
    is already sorted so for such arrays the partition will be at the middle
    of them

*/
    int partitionDisjoint(vector<int>& nums) {

        int diff = 0, n = nums.size();
        vector<int> arr = nums;

        sort(begin(arr), end(arr));

        bool all_equal_trend = (nums[0] == arr[0]);

        for(int i = 0; i < n; ++i){
            diff += (nums[i]-arr[i]);

            if(all_equal_trend){
                if(diff != 0) return i;
            } else {
                if(diff == 0) return i+1;
            }
        }

        return n/2;
    }
};

int main(){


    return 0;
}
