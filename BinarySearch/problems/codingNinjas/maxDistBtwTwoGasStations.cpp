

// # ther problem there are

//# 1.  with calculating the placedStation we can calculate only the integer we don't have to calcuate that also in integer

// # 2. checking whether the lastPlaced Station should not overlap with the existing station (dist != numberOfPlacedStations*mid)

#include <bits/stdc++.h>
using namespace std;
    bool isAmple(vector<int> arr,long double mid, int k){


        int i = 0, placed = 0;
        int dist;

        while(i < arr.size()-1){

            
            int numberOfPlacedStations = (arr[i+1]-arr[i])/mid;

            if(dist  == numberOfPlacedStations*mid) numberOfPlacedStations--;

            placed += numberOfPlacedStations;
            i++;

        }
        return placed<=k;
    }


    double minimiseMaxDistance(vector<int> &arr, int k){
        
        long double  hi,lo;
        hi=lo=0.0;

        int i =0, dist;

        while(i < arr.size()){

            if( (long double) (arr[i+1]-arr[i]) > hi){
                hi = (long double) arr[i+1]-arr[i];
            }
            i++;
        }

        while(hi-lo > 1e-6){
            long double mid  = (lo + hi)/2.0;

            if(isAmple(arr, mid, k)){
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }


int main()
{
    int n, k;
    vector<int> arr;

    cin >> n >> k;

    int i = 0;

    while (i < n)
    {
        int d;
        cin >> d;
        arr.emplace_back(d);
        i++;
    }

    cout << minimiseMaxDistance(arr, k);
    cout << endl;
    return 0;
}


// 10 1
// 1 2 3 4 5 6 7 8 9 10