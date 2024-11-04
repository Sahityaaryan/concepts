//solved it in O(N)

//! Must check the 2401_OPTIMIZED


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestNiceSubarray(vector<int> &nums)
{
    // revised approach

    int lead = 0,lag = 0,check = 0,n = nums.size(),res = 0;

    while(lead<n)
    {
        if((check&nums[lead])!= 0)
        {
            check ^= nums[lag++];
        }
        else
        {
            check |= nums[lead];
                res = max(res,lead-lag+1);
                lead++;
        }
    }

    return res;
}


int main(){

    cout << "revised approach";
    
    cout << endl;
    return 0;
}