#include<bits/stdc++.h>
using namespace std;


 bool isRequiredDistance(vector<int> stalls,int dist,int cows){

     int i = 1, n = stalls.size(), cowPlaced = 1 ,lastPlacedCows = stalls[0];

     while(i < n){
        
        if(lastPlacedCows+dist <= stalls[i]){
            cowPlaced++;
            lastPlacedCows = stalls[i];
        }
        i++;
     }
     
    if(cows<= cowPlaced) return true;

    return false;
 }

int aggressiveCows(vector<int> &stalls, int k)
{


    //* the best apporach to solve such questions is to store the value of "mid" in "ans" variable at the favourable
    //* condition then because sometimes either lo or hi can exceed the given condtion of lo<=hi and alter the required
    //* answer 


    // ! Not sure on this concept

    // but from this question i can say
    //* 1. maximum of minimum  -> return hi;
    //* 2. minimum of maximum  -> return lo;


    int lo = 1, hi, ans;

    // i will calcualte the distance 

    sort(stalls.begin(),stalls.end());

    hi = stalls[stalls.size()-1]-stalls[0];

    while(lo <= hi){
        int mid = lo + (hi-lo)/2;

        int cowPlaced = isRequiredDistance(stalls,mid,k);

        if(cowPlaced){
            // more cows placed
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }

    return hi;
}

int main()
{
 
    
    cout << endl;
    return 0;
}