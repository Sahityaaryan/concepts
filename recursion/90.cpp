#include<bits/stdc++.h>
using namespace std;


void print(vector<int>& v){

    cout << "{ ";

    for(auto it:v){
        cout << " " << it;
    }
    
    cout << " }";
}

void sol(int ind, vector<int>& tempArr, vector<vector<int>>& ans, vector<int>& arr){


    cout << ind << ' ';

    print(tempArr);

    ans.emplace_back(tempArr);

    cout << '\n';

    if(ind == arr.size()) return;

    for(int i = ind; i < arr.size();i++){

        if(i > ind && arr[i] == arr[i-1]) continue;

        tempArr.emplace_back(arr[i]);
        sol(i+1,tempArr,ans,arr);
        tempArr.pop_back();
        // if(i == arr.size()-1) cout << "end\n"; 
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

    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = subsetsWithDup(nums);

    cout << endl;
    return 0;
}