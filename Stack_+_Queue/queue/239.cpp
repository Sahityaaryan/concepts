#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

   int leader = 0, lagger = 0, max_ele = INT_MIN, sec_max_ele = INT_MIN, max_ind = -1, sec_max_ind = -1, n = nums.size();
    deque<int> dq;
   vector<int>maxSlidingWindowArray;

   while(leader < n){

            while(!dq.empty() && nums[dq.back()] <= nums[leader]){
                dq.pop_back();
            }
            dq.push_back(leader);

            if(leader - lagger + 1 == k){
                maxSlidingWindowArray.emplace_back(nums[dq.front()]);

                lagger++;

                if(lagger > dq.front()){
                    dq.pop_front();
                }

        }

    leader++;

   }

    return maxSlidingWindowArray;
}

int main(){

    return 0;
}
