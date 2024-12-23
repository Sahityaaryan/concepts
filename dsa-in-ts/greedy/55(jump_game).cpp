#include<bits/stdc++.h>
#include <vector>
using namespace std;


// It can be solved using both dp and iteration (optimized)
//
bool jumpCases(vector<int>& nums, vector<pair<bool, bool>>& dp, int ind){


    if(ind == nums.size()-1) return true;
    if(ind >= nums.size()) return false;
    if(dp[ind].first) return dp[ind].second;


    bool result = false;

    for(int i = 1; i <= nums[ind]; i++){
        result = result || jumpCases(nums, dp, ind + i);
        if(result) break;
    }

    dp[ind] = make_pair(true, result);

    return result;
}

bool canJump(vector<int>& nums) {
    // the maximum jump game

    // it smells like recursion -> checking by considering all the cases but it will be very costly to compute the
    // same results again and again so we will memoize the results by dp


    // dp => {haveYouEverEncounterThisIndexBefore, WillThisIndexWillLeadToFinalIndex}

    vector<pair<bool, bool>>dp (nums.size(), {false, false});
    return jumpCases(nums, dp, 0);

}



// ************************************************ OPtimized way O(N)

bool canJump2(vector<int>& nums) {
    // Initialize the maximum
    // index that can be reached
    int maxIndex = 0;

    // Iterate through each
    // index of the array
    for(int i = 0; i < nums.size(); i++){
        // If the current index is greater
        // than the maximum reachable index
        // it means we cannot move forward
        // and should return false
        if (i > maxIndex){
            return false;
        }

        // Update the maximum index
        // that can be reached by comparing
        // the current maxIndex with the sum of
        // the current index and the
        // maximum jump from that index
        maxIndex = max(maxIndex, i + nums[i]);
    }

    // If we complete the loop,
    //it means we can reach the
    // last index
    return true;
}




int main(){

 cout << endl;
return 0;

}
