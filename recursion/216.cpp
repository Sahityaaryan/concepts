#include<bits/stdc++.h>
using namespace std;

   void sol(int tempSum, int ind, int target, vector<int>& tempArr, vector<vector<int>>& ans, int k){


        if(tempSum == target){
            if(tempArr.size() == k){
                ans.emplace_back(tempArr);
            }
            return;
        }
        int i = ind;

        while(i <= 9){

            if(tempSum + i > target){
                return;
            }

            tempArr.emplace_back(i);

            sol(tempSum + i, i + 1, target, tempArr, ans, k);

            tempArr.pop_back();

            i++;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> tempArr;
        // vector<int> arr = {1,2,3,4,5,6,7,8,9};

        sol(0, 1, n, tempArr, ans, k);

        return ans;
    }

int main()
{
    cout << endl;
    return 0;
}