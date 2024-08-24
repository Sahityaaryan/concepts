#include<bits/stdc++.h>
using namespace std;

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int max_ele = *max_element(nums2.begin(), nums2.end());
        vector<int> nge(max_ele+1,-1);
        vector<int> ans(nums1.size(),-1);
        stack<int> st;

        int i = n-1;


        // stack will provide me the next greater element of the current Element and if stack becomes empty this mean that there is no 
        // greater element so insert -1

        for(int i = n-1; i >= 0; i--){
            
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            if(st.size() == 0){
                nge[nums2[i]] = -1;
            } else {
                nge[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        
        for(int i = 0;i < nums1.size(); i++){
            ans[i] = nge[nums1[i]];
        }

        return ans;


    }

int main()
{
  
  cout << endl;
  return 0;
}