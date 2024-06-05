#include<bits/stdc++.h>
using namespace std;

int numberBeforeTarget(vector<int> arr,int t){

    int lo = 0,n = arr.size(),hi = n-1,mid;

    while(lo <= hi){
        mid = lo + (hi-lo)/2;

        if(arr[mid] <= t){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return lo;
}

int findKthEle(vector<int> arr,int k){

    int mid,lo = 0,n = arr.size(),hi = arr[n-1];

    if(arr[n-1]-n < k){
        int diff = k - arr[n-1] + n;
        return hi+diff;
    }

    while(lo <= hi){

        mid = lo + (hi-lo)/2;

        int numberOfEleBefore = numberBeforeTarget(arr,mid);

        cout << "mid: " << mid << numberOfEleBefore << endl;

        if(numberOfEleBefore <= k ){
            lo = mid + 1;
        } else {
            hi = mid-1;
        }
    }

    return hi;
}

int main()
{
    vector<int> arr = {1,2,3,10};

    // cout << numberBeforeIt(arr,3);
    int k = 3;
    cout << findKthEle(arr,k); // 6


    
    cout << endl;
    return 0;
}