#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{

    int i = 0, j = 0,m = nums1.size(),n = nums2.size() , requiredIndex = (m+n)/2;
    float ans = 0, stepBack;    

    while (requiredIndex>=0 && j< m && i < m){

        if (nums1[i] < nums2[j]){
            stepBack = ans;
            ans = nums1[i];
            i++;
        } else {
            stepBack = ans;
            ans = nums2[j];
            j++;
        }
        requiredIndex--;
    }

    cout << "ans: " << ans << "stepback: " << stepBack << "requiredIndex: " << requiredIndex <<endl;

    while(requiredIndex >= 0 && i < m){
            stepBack = ans;
            ans = nums1[i];
            i++;
            requiredIndex--;
    }
    cout << "ans: " << ans << "stepback: " << stepBack << " requiredIndex: " << requiredIndex <<endl;

      while(requiredIndex >= 0 && j  < n){
        cout << "ans: " << ans << "stepback: " << stepBack <<endl;
            stepBack = ans;
            ans = nums2[j];
            j++;
    }

    cout << "2.ans: " << ans << "stepback: " << stepBack <<endl;

    if((m+n) % 2 == 0){
        return (float)(stepBack + ans)/2.0;
    }

    return ans;
    
}

int main()
{

    vector<int>nums1={1,2}, nums2 = {3,4};

  cout << "ans: " << findMedianSortedArrays(nums1, nums2);

    cout << endl;
    return 0;
}