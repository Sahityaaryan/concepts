#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

void subset_tracking(vector<int>& arr, int ind, int curr_min, int& sum){

    if(ind == arr.size()){
        sum = (int) (((long long) sum + curr_min) % MOD);
        return;
    }

    subset_tracking(arr, ind+1, min(curr_min,arr[ind]), sum);
    subset_tracking(arr, ind+1, curr_min, sum);
}
int sumSubarrayMins(vector<int>& arr) {

    int n = arr.size();
    for(int i = 0; i < n; i++){

    }
}


int main() {
    // Your code here

    cout << "#Developer";
    return 0;
}
