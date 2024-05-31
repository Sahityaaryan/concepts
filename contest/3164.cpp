#include<bits/stdc++.h>
using namespace std;






//  ************** solution to check for hint

 long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // unordered_map<long long,long long> mp;
        unordered_map<long long,long long> sp;
        // long long mini=1e9+10;
        // long long maxi=-1e9;
        
        
        // for(auto it:nums1) maxi=max(maxi,1ll*it);
        
        for(auto it:nums2){
            // mini=min(mini,(long long)(it*k));
            sp[1ll*(it*k)]++;
        }
        
        
        long long count=0;
        
        for(auto it:nums1){
            // if(it>=mini){
                for(int i=1; i<=sqrt(it); i++){
                    if(it%i!=0) continue;
                    count+=sp[i];
                    if(i!=it/i) count+=sp[it/i];

                }
            // }
        }
        
        return count;
    }
    















    int bs(vector<int> nums1, int target){ // target = nums2[j] * k
        int mid,lo = 0, hi = nums1.size()-1, ans=-1;

        while(lo <= hi){
            mid = lo + (hi-lo)/2;

            if(nums1[mid] < target){
                lo = mid+1;
            } else {
                ans = mid;
                hi = mid-1;
            }
        }

        return ans;
    }

    int countIfDivisible(vector<int> nums1, int mid,int divisor){
        int j = mid;
         int counter = 0; 
                  while(j < nums1.size()){
                      
                  if(!(nums1[j] % divisor)){
                    counter++;
                    }
                     j++;
                }

                return counter;
    }
    // countIfDivisible(nums1, nums2[i],k)
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
//         How to save some time?
//         1. memoization : store the answer in a map of some numbers that how many kpairs can be formed and without computing it we can give the answer
//         2. we don't have to check for the elements of nums1 which are lower than the k and nums2[i]. why don't we apply binary search for
//           searching bigger elements because the nums1 is looking sorted : 683/687


        sort(nums1.begin(), nums1.end()); // sorted the nums1 to apply the binary search

        
        unordered_map<int,int> mp;
        
         int i = 0, j = 0,counter = 0,mid;
        long long count = 0;
    
        
          while(i < nums2.size()){

            counter = 0;
            
            // apply binary search here
            if(mp[nums2[i]]){
                count += mp[nums2[i]];
            } else {
              mid = bs(nums1,nums2[i]*k);

              mp[nums2[i]] = counter = countIfDivisible(nums1, mid ,nums2[i]*k);
               count += counter;
             }
            i++;
            }

    
        return count;
        
    }

int main()
{
 
    
    vector<int> nums1 = {2,8,17,6};
    vector<int> nums2 = {3,1,1,8};

    nums1 = nums2 = {1,3,4};

    int k = 1;
   cout << "ans: " <<  numberOfPairs(nums1, nums2,k);
    cout << endl;
    return 0;
}

