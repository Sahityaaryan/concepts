#include<bits/stdc++.h>
using namespace std;


// important question

// Note :-> first check at which region the mid is lying then makes the condition according to it, 
// 1. if the region is left then we will try to make the target between the 0 and the mid that's why we keep on increasing the value of mid
// by throwing it towards the maximum number if condition doesn't satisfy.

// 2. if the region is right then we will try to make the target between the n-1 and mid that's why we keep on decreasing the value of mid
// by throwing it towards the minimum number if condition doesn't satisfy.

    int search(vector<int>& nums, int target) {

        int l = 0, r = nums.size()-1,ans = -1;

        if(r==-1) return -1;

       while(l <= r)
       {
           int mid = l + (r-l)/2;

           if(nums[mid]==target) ans = mid;

           if(nums[mid] > nums[nums.size()-1]) // checking the regiion
           {
               if(nums[mid] > target && target >= nums[0]) r = mid-1; // Making sure that the target is between mid and the 0
               else l = mid+1; // otherwise throw it towards the maximum number 

           } else {
               if(nums[mid] < target && target <= nums[nums.size()-1]) l = mid+1; // // Making sure that the target is between mid and the n-1
               else r = mid-1; // otherwise throw it towards the minimum number
           }
       }

       return ans;
        
    }

int main()
{
 
    
    cout << endl;
    return 0;
}