#include<bits/stdc++.h>
using namespace std;


int max1InArray(vector<int> arr){

    int lo = 0, hi = arr.size()-1,ans=-1,mid,n=arr.size();

    while(lo <= hi){

        mid = lo + (hi-lo)/2;

        if(arr[mid]){
            ans = max(n-mid,ans);
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m){
    
    int i = 0, cntMax = 0, ans=-1;

    while(i < n){

        int tempSum = max1InArray(matrix[i]);


        if(tempSum > cntMax) {
        // cout << "i: "<< i <<  " tempsum: "<< tempSum  << " cntMax: " << cntMax << endl;
            cntMax = tempSum;
            ans = i;
        }
        i++;
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = { {1,1,1} , {0,0,1} , {0,0,0}};

    int n = 3, m = 3;

    cout << "ans:  " << rowWithMax1s(matrix,n,m) << endl;

    return 0;
}