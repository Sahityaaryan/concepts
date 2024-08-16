#include<bits/stdc++.h>
using namespace std;

// Floor:-> Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than smallest element of arr[].

// Ceil :-> Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than greatest element of arr[].


 int findFloor(vector<long long> &v, long long n, long long x) {
            
            int lo = 0, hi = n -1;
            
            while(lo <= hi){
                int mid = lo + ((hi - lo) >> 1);
                
                if(v[mid] <= x){ 
                    lo = mid + 1;// finding the largest elment which satisfies the condition
                } else {
                    hi = mid - 1;
                }
            }
            
            return hi;
    }

     int findCeil(vector<long long> &v, long long n, long long x) {
            
            int lo = 0, hi = n -1;
            
            while(lo <= hi){
                int mid = lo + ((hi - lo) >> 1);
                
                if(v[mid] >= x){ 
                    hi = mid - 1;
                } else {
                    lo = mid + 1;// finding the smallest elment which satisfies the condition
                }
            }
            
            return lo;
    }



int main()
{
 
    
    cout << endl;
    return 0;
}