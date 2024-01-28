#include<bits/stdc++.h>

using namespace std;

/** Doubts
 *
 * 1. Why instead of checking the universal last (size-1) and first (0) of a vector we are comparing using the l and r which are
 * the instant first and last --
 * Ans: Because it will work as accordingly.
 *  
 * 
*/

    bool search(vector<int>& nums, int target) {

        int l = 0,n=nums.size(),r = n-1,t=target;

        if(n==0) return false;


        while(l<=r && nums[l]==nums[r])
        {
            if(nums[l]==t){ return true;}
            r--;
            l++;
        }
        
        while(l <= r)
        {
            int mid = l+(r-l)/2;


            if(nums[mid]==t) return true;

            if(nums[mid] > nums[r]){
                if(nums[mid]>t && nums[l]<=t)
                {
                    r = mid-1;
                } else l = mid+1;

            } else {

                if(nums[mid]<t && nums[r]>= t)
                {
                    l=mid+1;
                } else r=mid-1;
            }
        }


        return false;
    }

int main()
{
 
    vector<int>nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    int l=0,r=nums.size() -1;

    while(nums[l]==nums[r])
    {
        l++;
        r--;
    }

    // cout << l << ' ' << r << endl;

cout << nums[13] << endl;

    cout << endl;
    return 0;
}
