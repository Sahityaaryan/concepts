#include<bits/stdc++.h>
using namespace std;

int timeToEatNBananas(int bananas,int k){
        if(bananas % k==0) return bananas/k;
        return (bananas/k)+ 1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int lo = 1,n = piles.size(), hi =INT_MAX,i, timeToFinishBananas = 0 , minimumBananasPerHourSpeed = -1;

        // calculating the minimum and max piles

        i = 0;

        while(i < n){
            if(piles[i] > hi) hi = piles[i];

            // if(piles[i] < lo) lo = piles[i];

            i++;
        }

        while(lo <= hi){

            int mid = lo + (hi-lo)/2;

            i = 0;
            timeToFinishBananas = 0;

            while(i < n){
                timeToFinishBananas += timeToEatNBananas(piles[i],mid);
                i++;
            }

            // cout << timeToFinishBananas << endl;

            if(timeToFinishBananas > h){
                lo = mid + 1;
            } else {
                minimumBananasPerHourSpeed = mid;
                hi = mid - 1;
            }
        }

        return minimumBananasPerHourSpeed;
    }


int main()
{
 
    
    cout << endl;
    return 0;
}