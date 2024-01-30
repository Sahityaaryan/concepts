#include<bits/stdc++.h>
using namespace std;


 int singleNonDuplicate(vector<int>& nums) {

        // Intution: first check that the first element is consistent or not because if first occurs twice then the first occurence should always be on the even index and the second occurrence should always be in the odd index 

        // and if any twice occured element is not following the above criteria then the single occured element will be in its left otherwise it will be in its right
        
        vector<int> arr = nums;

        int n = arr.size() , lo =0, hi= n-1;

        if(n==1) return arr[lo];

        // checking for the first element 

        if(arr[lo] != arr[lo+1]) return arr[lo];

        if(arr[hi] != arr[hi-1]) return arr[hi];

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            if(arr[mid-1]==arr[mid]){
                
                if(mid % 2==0){
                    hi = mid - 1;
                } else {
                    lo = mid+1;
                }
            } else if(arr[mid] == arr[mid + 1]){
                if(mid % 2 != 0){
                    hi = mid -1;
                } else{
                    lo = mid + 1;
                }
            } else {
                return arr[mid];
            }
        }

        return arr[lo];
        
    }

int main()
{
 
    
    cout << endl;
    return 0;
}