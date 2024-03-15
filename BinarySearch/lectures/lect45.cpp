

#include<bits/stdc++.h>
using namespace std;

/**using recursion question -1 (upper bound and lower bound)*/

int bs(vector<int> v,int l,int r, int t)
{
    if(t>v[r]) return -1;

    if(t<v[l]) return -1;

    int mid = (l+r)/2;

    if(mid==l) return l;

    if(v[mid]==t)
    {
        return mid;x
    }
    else if(v[mid]>t)
    {
        return bs(v,l,mid-1,t);
    }

    return bs(v,mid+1,r,t);
}




int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}



/**upper bound and lower bound end*/



/**
 * question - 2
 * rotated sorted array
 * 
 * Rotations = last element ko first position pe lana
 * 
 * */

// my way

/**
 * space: O(logN)
 * time: O(N) 
 * N = size of array
*/

int minRotatedSortedArray(vector<int> &v,int l,int r)
{

    if(l>=r) return l;

    int first = (l+r)/2;

    int left_section = minRotatedSortedArray(v,l,first-1);
    int right_section = minRotatedSortedArray(v,first+1,r);

    int candidate = (v[left_section] > v[right_section] ? right_section:left_section);



    return (v[candidate] > v[first] ? first:candidate);
}



//sir modified by me

int sir(vector<int> input,int l,int r)
{
    if(input.size()==1) return input[0];

       //sorted array only case
    if(input[l] < input[r])
    {
        return l;
    }


    while(l <= r)
    {
        int mid = l + (r-l)/2;

   if(input[mid] < input[mid+1] && input[mid] < input[mid-1])
   {
    return mid;
   }
    if(input[mid] > input[l])
    {
        l = mid+1;
    }else {
        r = mid-1;
    }

    }

    return -1;
}

// not modified sir

int sir2(vector<int> input,int l,int r)
{
    if(input.size()==1) return input[0];

    //sorted array only case
    if(input[l] < input[r])
    {
        return l;
    }


    //roatated array case
    while(l <= r)
    {
        int mid = l + (r-l)/2;


    //here the given two conditions are the identifying condtion for min as the min element follows both the given condition
   if(input[mid] > input[mid+1])
   {
    return mid+1;
   }

   if(input[mid] < input[mid-1])
   {
    return mid;
   }
    if(input[mid] > input[l])
    {
        l = mid+1;
    }else {
        r = mid-1;
    }

    }

    return -1;
}



/*
 * question: 3
 * 
 * find the target in the rotated array;
*/

//my way

int findTargetInRotatedSortedArray(vector<int> v,int t)
{
        int min = minRotatedSortedArray(v,0,v.size()-1);

        if(v[min]==t) return min;

        int left = bs(v,0,min-1,t);
        int right = bs(v,min+1,v.size()-1,t);

        if(left==-1) return right;

        return left;
}

// sir's way

/**
 * In rotated Sorted array
 * 
 * sorted region 1: first element to maximum element
 * 
 * sorted region 2: minimum element to last element
 * 
 * method : ki check karte raho ki sorted region mein target pada hai agar nhi to mid ko opposite region mein shift kar do
*/

int sir3(vector<int> v,int t)
{
    int l = 0,r = v.size()-1,mid;

    while(l <= r)
    {
        mid = (l+r)/2;

        if(v[mid]==t) return mid;

        if(v[mid] >= v[r])
        {
            if(t>v[l] && t <= v[mid])
            {
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }else
        {
            if(t>v[mid] && t <= v[r])
            {
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
    }

    return -1;

}


/**
 * QUESTION 4:
 * 
 * Here there is an edge case when the repeated sorted array contains duplicate elements so 
 * here our first and the last element can be same but they have to be different such that
 * we can differentiate between them whether the array is repeated sorted or not
 * 
 * 
*/



int duplicateRepeatedSortedArray(vector<int> v,int t)
{
    int l = 0,r = v.size()-1,mid;

    //if the first and last elements are same then just check them 
    // whether they are the required target or not

    while(v[l]==v[r])
    {
        if(v[l]==t) return 1;

        l++;
        r--;
    }

    // rest is same like the searching an element in the rotated sorted array 

    while(l <= r)
    {
        mid = (l+r)/2;

        if(v[mid]==t) return 1;

        if(v[mid] >= v[r])
        {
            if(t>v[l] && t <= v[mid])
            {
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }else
        {
            if(t>v[mid] && t <= v[r])
            {
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
    }

    return -1;

}




int main()
{
    int n,target = 3;

    vector<int> input = {1,2,3,5,11};

    cout << "lower: " <<  lowerBoundLoop(input,target);
    cout << "upper: " <<  upperBound(input,0,input.size()-1,target);

    //***** quetion: 2

    // vector<int> v= {3,4,5,6,1,2};
    //  vector<int> v={1,2,3,4,5};

    // // cout << "min: " << minRotatedSortedArray(v,0,v.size()-1);

    // cout << "min: " << sir2(v,0,v.size()-1);


    /**
     * question: 3
    */

   vector<int> v= {0,0,0,1,1,1,2,0,0,0};
//  vector<int> v= {1,2,3,4,5,6};

//    int target = 0;
//    cout << "position: " << findTargetInRotatedSortedArray(v,target);

    // cout << "position: " << sir3(v,target);


    //  cout << "ans: "<<   duplicateRepeatedSortedArray(v,target);
    cout << endl;
    return 0;
}
