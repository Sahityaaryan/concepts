#include<bits/stdc++.h>
using namespace std;

    void sol(int& tempSum, int ind, int target, vector<int>& tempArr, vector<int>& arr, vector<vector<int>>& ans){

        if(tempSum == target){
            ans.emplace_back(tempArr);
            return;
        }

        int i = ind;

        while(i < arr.size()){


            if(i > ind && arr[i-1] == arr[i]){ // Don't make a call with dupliacte elements because if the further elements are duplicate 
            // then also they will get the chance of a function call because the first index of the next function call will always be
            // executed. --> thus reducing the chance of duplicacy

            // we are two duplciate elements two posibilities .-> tempusum + same1 , tempusum + same1 + same2, tempusum + same2 , wo we are getting the same sum two times and if the nuumber repeat more than two times then it will lead to a huge branch of recursions and lead to memory exhaustion

            // but by this we got this :-> tempusum + same1 , tempusum + same1 + same2 (in the next call after the first possibility)
                i++;
                continue;
            }

            if(arr[i] + tempSum > target){ // if the sum is more than the target stop the further calls
                break;
            }

            tempArr.emplace_back(arr[i]);
            tempSum += arr[i];
            sol(tempSum , i+1, target, tempArr, arr,ans);
            tempSum-=arr[i];
            tempArr.pop_back();
            
            i++;
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());
        
        vector<vector<int>> ans;
        vector<int> tempArr;
        int tempSum = 0;

        sol(tempSum, 0, target,tempArr,candidates, ans);

        return ans;
    }

int main()
{

    vector<int> nums = {1,2,3};

    int i = 0;

    vector<vector<int>> bs;

    bs.push_back({1,2,3});

    if(bs[0]==nums){
        cout << "it is working" << endl;
    }
    
    cout << endl;
    return 0;
}