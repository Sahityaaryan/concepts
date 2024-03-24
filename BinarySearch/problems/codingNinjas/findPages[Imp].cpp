#include <bits/stdc++.h>
using namespace std;

// ! Mistake i was makeing
// * 1. Not taking care that lo should be the maximun pages present in the array and the required answer will be greater than the max pages if (n (number of books) > m)

bool isAmple(int mid, vector<int> &arr, int m)
{

    int sum = 0, lo = 0, n = arr.size(), count = 1;

    while (lo < n)
    {

        sum += arr[lo];

        if (sum > mid)
        {
            sum = arr[lo];
            count++;
        }

        lo++;
    }

    return (count <= m);
}

int findPages(vector<int> &arr, int n, int m)
{

    int lo = 0, hi = 0, ans, mid, sum = 0;
    // edge case: when number of students are less than the number of books available

    if (m > n)
    {
        return -1;
    }

    while (lo < n){
        hi += arr[lo];
        lo++;
    }

    lo = *max_element(arr.begin(), arr.end());

    while (lo <= hi)
    {

        mid = (lo + hi) / 2;

        if (isAmple(mid, arr, m))
        {
            // ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return lo;
}

int main()
{

    vector<int> arr;

    int m, n;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int lo;
        cin >> lo;
        arr.push_back(lo);
    }

    cout << "ans: " << findPages(arr, n, m) << endl;

    cout << endl;
    return 0;
}