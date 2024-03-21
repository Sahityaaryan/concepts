#include<bits/stdc++.h>
using namespace std;


//# Question: https://www.codingninjas.com/studio/problems/minimum-rate-to-eat-bananas_7449064?leftPanelTabValue=PROBLEM

//* what have I learned:

bool isAmple(int m, vector<int> v, int h){

    int hours = 0;

    int i = 0;

    while(i < v.size()){

        hours += ((v[i] % m != 0)? (v[i]/m+1):(v[i]/m));
        i++;

        if(hours > h) return false;
    }
    return true;
}

int minimumRateToEatBananas(vector<int> v, int h) {
   

    int lo = 1;
    int hi = *(max_element(v.begin(), v.end()));
    int mid;

    while(lo <= hi){

        mid = lo + (hi-lo) / 2;

        if(isAmple(mid,v,h)){
            hi = mid-1;
        } else {
            lo = mid + 1;
        }
    }

    return lo;
    
}

int main()
{
 
    
    cout << endl;
    return 0;
}