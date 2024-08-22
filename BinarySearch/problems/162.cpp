#include<bits/stdc++.h>
using namespace std;

// here you just have to adjust by seeing the left and the right elments 

 int findPeakElement(vector<int>& nums) {

        int n = nums.size() , lo  =0, hi = n-1;

        if (n==1) return 0;

        while(lo <= hi){

            int mid = lo + (hi-lo)/2;

            if(mid==n-1) return mid; // reason becasue mid +1 will give overflow and my code will handle the lower cases 

            if(nums[mid] < nums[mid+1]) {

                lo = mid + 1;

            } else {
                hi = mid - 1;
            }
                
        }
        
        return lo;
    }

int main()
{
 
    
    cout << endl;
    return 0;
}