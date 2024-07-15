

// # ther problem there are

//# 1.  with calculating the placedStation we can calculate only the integer we don't have to calcuate that also in integer

// # 2. checking whether the lastPlaced Station should not overlap with the existing station (dist != numberOfPlacedStations*mid)

#include <bits/stdc++.h>
using namespace std;
    int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

  
    double findSmallestMaxDist(vector<int> &stations, int k) {
        vector<int> arr = stations;
      int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
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