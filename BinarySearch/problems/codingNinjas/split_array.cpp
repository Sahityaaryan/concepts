
// # link: https://www.naukri.com/code360/problems/largest-subarray-sum-minimized_7461751

#include<bits/stdc++.h>
using namespace std;



// In the question below I was wrong at the choice of lo it should be the max_element because the largest sum of a subarray of an array is its max_element 

int numberOfSubArrays(vector<int> a, int mid){

    int i = 0, count = 1;
    long long sum = 0;

    while(i < a.size()){
        
        sum += a[i];
        if(sum > mid){
            sum = a[i];
            count++;
        }

        i++;
    }

    return count;
}


int largestSubarraySumMinimized(vector<int> a, int k) {
        int n = 0,mid,ans = -1;
    int lo = *(max_element(a.begin(),a.end())); // this is the missing part
    // int hi = sumOfElements(a);
    int hi = accumulate(a.begin(), a.end(), 0);

//  intelligent guessing the maximum sum 
    while(lo <= hi){

        mid = lo + (hi-lo)/2;

        int subArrays = numberOfSubArrays(a, mid);

        if(k < subArrays){
            lo = mid + 1;
        } else {
            ans = mid;
            hi = mid-1;
        }
    }

    return ans;

}


int main()
{
 
    vector<int> a = {1,200,3,4};

    cout << endl;
    return 0;
}