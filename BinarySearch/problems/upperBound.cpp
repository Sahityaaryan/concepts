#include<bits/stdc++.h>
using namespace std;

// why I am able to return the hi and not the lo how can I say this?
// * Ans: because at the implementation of the binary search the hi and lo becomes adjacent often, so we just have to check that which block
// * will give us the correct answer when the hi and lo become adjacent. and in this case the hi will be the answer as if we found a mid
// * which will satisfy the condition the lo will be updated by the one so lo can't be the correct answer but when we found an incorrect mid
// * due to lo the hi will reduce by one so hi could give us the correct answer.

     int upperBound(vector<int> &nums,int t){

        int i = 0,ans = -1, lo = 0, hi = nums.size()-1;

        while(lo <= hi){   
            int mid = lo + (hi-lo)/2;

            if(nums[mid]<=t){
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }

        return (hi >= 0 && nums[hi] == t) ? hi:-1; // and this is for ArrayOutOfBoundsException 
    }

int main(){

    
    cout << endl;
    return 0;
}