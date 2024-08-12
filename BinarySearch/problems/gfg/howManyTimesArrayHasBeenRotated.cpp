#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        int mid;
        while(left<=right)
        {
            mid = (left+right)/2;
            if(arr[0]>arr[mid]) right = mid-1; 
            else left = mid+1;
        }
        return (left == n ? 0:left);
    }

// this is the most optimized way of checking that how many times the array has been rotated

int main()
{
 
    
    cout << endl;
    return 0;
}