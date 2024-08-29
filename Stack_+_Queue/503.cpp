#include<bits/stdc++.h>
using namespace std;


// here the logic is simple first of all i will place the next greater element from last to first and then in the second iteration i will start filling the nge array

  vector<int> nextGreaterElements(vector<int>& nums) {

        stack<int> st; int n=nums.size();
            vector<int>ans(n);
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<= nums[i%n]){
                st.pop();
            }
            if(i<n){
                if(!st.empty()){
                    ans[i]=st.top();
                }else ans[i]=-1;
            }
            st.push(nums[i%n]);
        }
        return ans;
    }

int main()
{
  return 0;
}
