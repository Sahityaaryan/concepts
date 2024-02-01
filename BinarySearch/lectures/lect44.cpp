#include<bits/stdc++.h>
using namespace std;

/**
 * BINARY SEARCH
 *  time: O(x) [x= inputted number]
 *  space: O(1)
 * 
 * ITERATIONS
 *   time: O(sqrt(x))
 *   space: O(1)
 * 
 * explaination of the above TC. is that kisi particular size se 1 pe jaane mein kitan baar half ya division 
 * karna padega
 * 
*/


int sqr(int x)
{
    int lo = 1,hi = x;
    int ans = -1,mid;
    while(lo<=hi)
    {
         mid = lo+(hi-lo)/2;

         if(mid*mid <= x)
         {
            ans = mid;
            lo = mid+1;
         }else{
            hi = mid-1;
         }
    }

    return ans;
}



int main()
{
 
    int a;
    cin >> a;

   cout << sqr(a);
    cout << endl;
    return 0;
}