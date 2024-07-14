#include<bits/stdc++.h>
using namespace std;

    void subsetMaking(vector<int>& nums ,vector<vector<int>>& subsetArray,vector<int> arr ,int index){
        if(!(index+1)){
            subsetArray.emplace_back(arr);
            return;
        }

        arr.emplace_back(nums[index]);
        subsetMaking(nums,subsetArray, arr, index-1);
        arr.pop_back();
        subsetMaking(nums,subsetArray, arr, index-1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> subsetArray;
        subsetMaking(nums, subsetArray, {} ,nums.size()-1);
        return subsetArray;
    }

int main()
{
    cout << endl;
    return 0;
}