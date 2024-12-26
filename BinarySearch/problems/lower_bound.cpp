#include<bits/stdc++.h>
using namespace std;


// Lower bound = maximum element less than the target

    int LBs(vector<int> &nums,int t,int lo, int hi){

        int i = 0,ans =-1;

        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;

            if(nums[mid] < t){
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }

        return (lo < nums.size() && nums[lo] == t) ? lo:-1;
    }

    int main(){


        cout << endl;
        return 0;
    }
