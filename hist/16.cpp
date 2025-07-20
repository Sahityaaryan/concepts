#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        // article to read-> https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d
        int global_max=arr[0], local_max=0;

        for(int ele:arr){
            local_max = max(local_max+ele,ele);
            global_max = max(global_max,local_max);
        }

        return global_max;
    }
};

int main(){

    return 0;
}
