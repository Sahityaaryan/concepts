#include<bits/stdc++.h>
using namespace std;

    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        
        if(n > m){ 
          return  kthElement(arr2,arr1,m,n,k);
        }

        
        int lo = max(0,k-m);
        int hi = min(k,n);
        int mid,mid1,mid2,l1,l2,r1,r2;
        
        while(lo <= hi){
            
            mid = lo + (hi-lo)/2;
            
            mid1 = mid;
            mid2 = k - mid;
            
            l1 = (mid1 > 0) ? arr1[mid1-1]:INT_MIN;
            l2 = (mid2 > 0) ? arr2[mid2-1]:INT_MIN;
            r1 = (mid1 < n) ? arr1[mid1]:INT_MAX;
            r2 = (mid2 < m) ? arr2[mid2]:INT_MAX;
            
            
            if(l1 <= r2 && l2 <= r1){
                return max(l2,l1);
            } else if(l1 > r2){
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
            
        }
        
        
        return -1;
        
        
    }

int main()
{
 
    
    cout << endl;
    return 0;
}