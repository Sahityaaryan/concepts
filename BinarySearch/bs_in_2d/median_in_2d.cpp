#include <bits/stdc++.h>
using namespace std;


// striver says that: T.C = R * log(C)

// me =  T.C = log(R*C)*(R * log(C)); // because we actually want to find that number who is in middle of that array which is formed when all the elements are included into it in sorted order.

// this will take a long time to fix things on the place

int calculateTheLessNumber(vector<vector<int>> v , int mid){

    int i  = 0,j = 0,count = 0;

    while(i < v.size()){

        j = 0;
        
        int lo = 0;
        int hi = v[0].size() - 1;

        while(lo <= hi){
            int md = lo + (hi-lo)/2;

            if(mid < v[i][md]){
                hi = md-1;
            } else {
                lo = md + 1;
            } 
            j++;
        }

        count += lo;
        i++;
    }

    return count;
}

int median(vector<vector<int>> &matrix, int R, int C)
{
    int mid, lo = INT_MAX, hi = INT_MIN, i = 0, j = 0, count = (R * C + 1) / 2;

    while (i < R)
    {
        lo = min(matrix[i][0], lo);
        hi = max(matrix[i][C - 1], hi);
        i++;
    }

    i = 0;

    while (lo < hi){
        mid = (lo + hi) / 2;

        if (count <= calculateTheLessNumber(matrix,mid)){
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }

    return lo;
}

