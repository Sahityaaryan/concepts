#include <bits/stdc++.h>
using namespace std;

void sol(int tempSum, int ind, int target, vector<int> &tempArr, vector<vector<int>> &ans, vector<int> &arr)
{

    if (tempSum == target)
    {
        ans.emplace_back(tempArr);
        return;
    }

    if (tempSum > target || ind == arr.size())
    {
        return;
    }

    tempArr.emplace_back(arr[ind]);
    sol(tempSum + arr[ind], ind, target, tempArr, ans, arr);
    tempArr.pop_back();

    sol(tempSum, ind + 1, target, tempArr, ans, arr);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{

    vector<vector<int>> ans;

    vector<int> tempArr;

    sol(0, 0, target, tempArr, ans, candidates);

    return ans;
}

int main()
{
    cout << endl;
    return 0;
}