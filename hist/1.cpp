#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


    /*
     *
     * question-> 768 (leetcode) -> https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

        Learning :-> here the questions is actually want to say that "give me the
        total number of groups of elements of the arr which if sorted then the area
        of that grp will become equal to that same area of the sorted array"

        **Law** = so it means that all the element which will be there (in that
         area of grp)  when the array is sorted, should be there in the grp when
        that grp or subarray is not sorted.

        [2,1,3,4,4]
        [1,2,3,4,4]

        -> we can clearly see that according to the **Law** these grp or subarray
        we get -> [2,1], [3], [4], [4]

        so now this becomes our junk because we just have to sort thosee grp and
        nothing else

        ### Approach

        okay so there will always be one thing common between then whether they
        are sorted or not and it's there sum.

        sum([2,1]) == sum([1,2]) == 3
        sum([3]) == sum([3]) == 3
        sum([4]) == sum([4]) == 4
        sum([4]) == sum([4]) == 4

        so if we create there prefix sum array then ,
        (no. of chunks) == (no. of elements which are common in the prefix sum
        of both sorted and unsorted array)

        and exactly same kind of logic is also used in the "diff" method

    */

    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), count = 0;
        int mod = 1e9+7;

        vector<int> prefix_sum_unsorted(n,0);
        vector<int> prefix_sum_sorted(n,0);
        prefix_sum_unsorted[0]= arr[0];


        vector<int> nums = arr;
        sort(begin(nums), end(nums));

        prefix_sum_sorted[0] = nums[0];

        for(int i = 1; i < n; ++i){
            prefix_sum_unsorted[i] = (prefix_sum_unsorted[i-1]%mod + arr[i]%mod)%mod;
        }

        for(int i = 1; i < n; ++i){
            prefix_sum_sorted[i] = (prefix_sum_sorted[i-1]%mod + nums[i]%mod)%mod;
        }

        for(int i = 0; i < n; ++i){
            if(prefix_sum_sorted[i] == prefix_sum_unsorted[i]) count++;
        }

        return count;
    }

    // int maxChunksToSorted(vector<int>& arr) {
    //     int n = arr.size(), count = 0;
    //     int mod = 1e9+7;

    //     vector<int> nums = arr;
    //     sort(begin(nums), end(nums));

    //     int diff = 0;

    //     for(int i = 0; i < n; ++i){
    //         diff = (diff%mod + arr[i] - nums[i])%mod;
    //         if(diff == 0) count++;
    //     }

    //     return count;
    // }


};

int main(){

    return 0;
}


// -> of similar kind -> 915 2957 1248 -- (all completed)
// and from this I can say that understanding the pattern of solving the question is more important because
// the computer is a very dumb machine it needs to follow a regular pattern to do anything it can't think
// and changes it ways like us.
//
