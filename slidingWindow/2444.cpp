#include<bits/stdc++.h>
using namespace std;
 

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
         int mink = minK, maxk = maxK;
        int cup = -1, minp = -1, maxp = -1, n = nums.size();
        long long count = 0;
        for(int i = 0; i < n; i++){

            if(nums[i] < mink || nums[i] > maxk) cup = i;
            
             if(nums[i] == maxk) maxp = i;
             if(nums[i] == mink) minp = i;
            long long smaller = min(minp, maxp);
            long long temp = smaller - cup;

            count += (temp < 0 ? 0:temp);
        }

        return count;
    }

int main(){
    
 cout << endl;
return 0;
}