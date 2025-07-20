#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
        Leetcode (152) -> here you just have to see the thing that
        -ve * -ve == +ve
        and -ve * +ve == -ve

        so sometimes the positive maxima can become minima and the
        negative minima can become positive maxima
    */

    int maxProduct(vector<int>& nums) {

        int local_max = 1, global_max = INT_MIN,local_min = 1;

        for(int num:nums){
            int prev = local_max;
            local_max = max(local_max*num,max(num, local_min*num));
            local_min = min(local_min*num,min(num,prev*num));
            global_max = max(local_max, global_max);
        }
        return global_max;
    }
};

int main(){

    return 0;
}
