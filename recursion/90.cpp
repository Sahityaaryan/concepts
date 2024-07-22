#include<bits/stdc++.h>
using namespace std;

void sol(int ind, vector<int>& tempArr, vector<vector<int>>& ans, vector<int>& arr){

    ans.emplace_back(tempArr);

    if(ind == arr.size()) return;

    for(int i = ind; i < arr.size();i++){

        if(i > ind && arr[i] == arr[i-1]) continue;

        tempArr.emplace_back(arr[i]);
        sol(i+1,tempArr,ans,arr);
        tempArr.pop_back();
    }
}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> tempArr;
        sol(0,tempArr, ans, nums);


        return ans;
    }

int main()
{
    cout << endl;
    return 0;
}