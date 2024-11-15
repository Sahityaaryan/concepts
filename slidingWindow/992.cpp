#include<bits/stdc++.h>
using namespace std;
 
 int sol(vector<int>& nums, int k){
        int lead = 0, lag = 0, window = 0, dist_count = 0;

        int hsh[10];
        fill(hsh, hsh+10, 0);

        while(lead < nums.size()){
            hsh[nums[lead]]++;

            if(hsh[nums[lead]] == 1){
                dist_count++;
            }

            while(dist_count > k){

                hsh[nums[lag]]--;

                if(hsh[nums[lag]] == 0){
                    dist_count--;
                }

                lag++;
            }

            window += (lead - lag + 1);
            lead++;
        }

        return window;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sol(nums, k) - sol(nums, k-1);
    }


int main(){
    
 cout << endl;
return 0;
}